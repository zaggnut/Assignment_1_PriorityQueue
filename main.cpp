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
#include <random>
#include <chrono>

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rand = std::default_random_engine(seed);
    PCB_Table table;
    try
    {
        for(unsigned i = 1; i < 1000000; i++)
        {
            //auto block = createPCB(processState::NEW, i, i % 50 + 1);
            table.addNewProcess(processState::NEW, i, i % 49 + 1);
        }
        table.getPCB(20)->state = processState::RUNNING;
        //block->state = processState::RUNNING;
        while(table.size() != 0)
        {
            
            table.terminateProcess(table.getKeyVector()[rand() % table.size()]);
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