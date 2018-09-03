/*
    PCB Table implementation file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/02/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"

PCB_Table::PCB_Table()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rand = std::default_random_engine(seed); //seed the random engine with system time
}

void PCB_Table::addNewPCB(ProcessControlBlock &process)
{
    auto ret = ProcessMap.insert(std::pair<PCB_ID_TYPE, ProcessControlBlock &>(process.ID, process));
    if (ret.second == false) //was the insert unsuccessful?
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
    return ProcessMap.at(ID);
}

ProcessControlBlock &PCB_Table::removePCB(PCB_ID_TYPE ID)
{
    if (ProcessMap.count(ID) == 0)
    {
        throw ProcessNotFoundException();
    }
    ProcessControlBlock removedBlock = ProcessMap.at(ID);
    ProcessMap.erase(ID);
    return removedBlock;
}

ProcessControlBlock &PCB_Table::getRandomPCB()
{
    if(ProcessMap.empty())
    {
        throw ProcessNotFoundException();
    }
    unsigned count = rand() % ProcessMap.size();
    std::map<PCB_ID_TYPE, ProcessControlBlock &>::const_iterator it = ProcessMap.cbegin();
    for(int i = 0; i < count; i++)
    {
        it++; //cannot directly add count to it since it is an iterator
    }
    PCB_ID_TYPE key = it->first;
    ProcessControlBlock removedBlock = it->second;
    ProcessMap.erase(key);
    return removedBlock;
}

void PCB_Table::clear()
{
    ProcessMap.clear();
}