/*
    Main C++ file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#include "PCB.hpp"
#include "PCB_Table.hpp"
#include <iostream>

int main()
{
    PCB_Table table(1000000);
    try
    {
        for(unsigned i = 1; i < 1000000; i++)
        {
            auto block = createPCB(processState::NEW, i, i % 50 + 1);
            table.addNewPCB(block);
        }
        auto block = table.getPCB(20);
        block->state = processState::RUNNING;
        while(table.size() != 0)
        {
            auto block = table.removeRandomPCB();
            //std::cout << *block << std::endl;
        }
    }
    catch(InsertFailedException e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(ProcessNotFoundException e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}