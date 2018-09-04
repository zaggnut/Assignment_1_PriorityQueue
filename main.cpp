/*
    Main C++ file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/01/18
    Last Update By: Michael Lingo

*/

#include "PCB_Table.hpp"
#include <iostream>

int main()
{
    PCB_Table table;
    try
    {
        for(unsigned i = 1; i < 1'000'000; i++)
        {
            table.addNewPCB(createPCB(processState::NEW, i, i % 49 + 1));
        }
        table.getPCB(20).state = processState::WAITING;
        std::cout << sizeof(table) << std::endl;
        while(table.size() != 0)
        {
            auto block = table.removeRandomPCB();
            //std::cout << block << std::endl;
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