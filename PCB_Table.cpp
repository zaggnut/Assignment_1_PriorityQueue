/*
    PCB Table implementation file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/03/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"

PCB_Table::PCB_Table()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    keyVector.reserve(50);
    rand = std::default_random_engine(seed); //seed the random engine with system time
}

void PCB_Table::addNewPCB(ProcessControlBlock &process)
{
    if (ProcessMap.count(process.ID) != 0) //Is a process with this ID already in the map?
    {
        throw InsertFailedException();
    }
    keyVector.push_back(process.ID);

    PCBKeyStruct toInsert = {keyVector.size() - 1, process};
    auto ret = ProcessMap.insert(std::pair<PCB_ID_TYPE, PCBKeyStruct>(process.ID, toInsert));
    if (ret.second == false) //was the insert unsuccessful for some reason?
    {
        throw InsertFailedException();
    }
}

ProcessControlBlock &PCB_Table::getPCB(PCB_ID_TYPE ID)
{
    if (ProcessMap.count(ID) == 0)
    {
        throw ProcessNotFoundException();
    }
    return ProcessMap.at(ID).block;
}

ProcessControlBlock &PCB_Table::removePCB(PCB_ID_TYPE ID)
{
    if (ProcessMap.count(ID) == 0)
    {
        throw ProcessNotFoundException();
    }
    PCBKeyStruct removedBlock = ProcessMap.at(ID);
    if (ProcessMap.size() > 1) //no point in doing this if there is only one item in the map
    {
        unsigned toSwap = removedBlock.processVectorIndex;
        ProcessMap.at(keyVector[keyVector.size() - 1]).processVectorIndex = toSwap;
        keyVector[toSwap] = keyVector[keyVector.size() - 1]; //move toSwap to the last element
    }
    keyVector.pop_back(); //remove the last element from the vector
    ProcessMap.erase(ID);
    return removedBlock.block;
}

ProcessControlBlock &PCB_Table::removeRandomPCB()
{
    if (ProcessMap.empty())
    {
        throw ProcessNotFoundException();
    }
    unsigned pos = rand() % ProcessMap.size();
    return removePCB(keyVector[pos]);
}

void PCB_Table::clear()
{
    ProcessMap.clear();
    keyVector.clear();
}