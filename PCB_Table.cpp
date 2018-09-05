/*
    PCB Table implementation file, requires C++11
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"

unsigned long PCB_Table::size()
{
    return keyVector.size();
}

const std::vector<PCB_ID_TYPE> &PCB_Table::getKeyVector() const
{
    return keyVector;
}

void PCB_Table::addNewProcess(processState state, PCB_ID_TYPE ID, unsigned priority)
{
    if (ProcessMap.count(ID) != 0) //Is a process with this ID already in the map?
    {
        throw InsertFailedException();
    }
    keyVector.push_back(ID);

    PCBKeyStruct toInsert{keyVector.size() - 1, std::unique_ptr<ProcessControlBlock>(new ProcessControlBlock{state, ID, priority})};
    auto ret = ProcessMap.insert(std::pair<PCB_ID_TYPE, PCBKeyStruct>(ID, std::move(toInsert)));
    if (ret.second == false) //was the insert unsuccessful for some reason?
    {
        keyVector.pop_back(); //remove the recently added key
        throw InsertFailedException();
    }
}

std::unique_ptr<ProcessControlBlock> &PCB_Table::getPCB(PCB_ID_TYPE ID)
{
    if (ProcessMap.count(ID) == 0)
    {
        throw ProcessNotFoundException();
    }
    return ProcessMap.at(ID).block;
}

void PCB_Table::terminateProcess(PCB_ID_TYPE processID)
{
    if (ProcessMap.count(processID) == 0)
    {
        throw ProcessNotFoundException();
    }
    //PCBKeyStruct removedBlock = ProcessMap.at(processID);
    if (ProcessMap.size() > 1) //no point in doing this if there is only one item in the map
    {
        unsigned toSwap = ProcessMap.at(processID).processVectorIndex;
        ProcessMap.at(keyVector[keyVector.size() - 1]).processVectorIndex = toSwap;
        keyVector[toSwap] = keyVector[keyVector.size() - 1]; //move toSwap to the last element
    }
    keyVector.pop_back(); //remove the last element from the vector
    ProcessMap.erase(processID);
}

void PCB_Table::clear()
{
    ProcessMap.clear();
    keyVector.clear();
}