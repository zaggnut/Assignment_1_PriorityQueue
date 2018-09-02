/*
    PCB Table implementation file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/02/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"

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
    else
        return ProcessMap.at(ID);
}