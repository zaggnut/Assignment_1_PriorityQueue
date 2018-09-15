/*
    PCB Table implementation file, requires C++11
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"

PCB_Table::PCB_Table()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rand = std::default_random_engine(seed); //seed the random engine with system time
}

PCB_Table::PCB_Table(unsigned initialSize)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rand = std::default_random_engine(seed); //seed the random engine with system time
    keyVector.reserve(initialSize);
    ProcessMap.reserve(initialSize);
}

unsigned long PCB_Table::size()
{
    return keyVector.size();
}

void PCB_Table::addNewPCB(std::shared_ptr<ProcessControlBlock> process)
{
    if (ProcessMap.count(process->ID) != 0) //Is a process with this ID already in the map?
    {
        throw InsertFailedException();
    }
    keyVector.push_back(process->ID);
    //auto ret = ProcessMap.emplace(process->ID, keyVector.size() -1, process);
    auto ret = ProcessMap.emplace(std::piecewise_construct, 
        std::forward_as_tuple(process->ID),
        std::forward_as_tuple(keyVector.size() - 1, process));
    //PCBKeyStruct toInsert{keyVector.size() - 1, process};
    //auto ret = ProcessMap.insert(std::pair<PCB_ID_TYPE, PCBKeyStruct>(process->ID, toInsert));
    if (ret.second == false) //was the insert unsuccessful for some reason?
    {
        keyVector.pop_back(); //remove the recently added key
        throw InsertFailedException();
    }
}

void PCB_Table::addNewPCB(processState state, PCB_ID_TYPE ID_, unsigned Priority)
{
    keyVector.push_back(ID_);
    auto ret = ProcessMap.emplace(std::piecewise_construct, 
        std::forward_as_tuple(ID_),
        std::forward_as_tuple(keyVector.size() - 1,
        createPCB(state, ID_, Priority)));

    if(ret.second == false)
    {
        keyVector.pop_back();
        throw InsertFailedException();
    }

}

std::shared_ptr<ProcessControlBlock> &PCB_Table::getPCB(PCB_ID_TYPE ID)
{
    if (ProcessMap.count(ID) == 0)
    {
        throw ProcessNotFoundException();
    }
    return ProcessMap.at(ID).block;
}

const std::vector<PCB_ID_TYPE> &PCB_Table::getKeyVector() const
{
    return keyVector;
}

std::shared_ptr<ProcessControlBlock> PCB_Table::removePCB(PCB_ID_TYPE ID)
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

std::shared_ptr<ProcessControlBlock> PCB_Table::removeRandomPCB()
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