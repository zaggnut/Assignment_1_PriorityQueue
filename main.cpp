/*
    Main C++ file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#include "PCB.hpp"
#include "PCB_Table.hpp"
#include "PriorityQueuePCB.hpp"
#include <iostream>
#include <random>
#include <chrono>


void test1(PCB_Table& table, PriorityQueuePCB& queue)
{
    //add 5, 1, 8, and 11
    queue.addPCB(table.getPCB(5));
    queue.addPCB(table.getPCB(1));
    queue.addPCB(table.getPCB(8));
    queue.addPCB(table.getPCB(11));
    queue.PrintPriorityQueue();
    auto block = queue.removePCB();
    //remove the highest priority and print
    block->state = processState::RUNNING;
    queue.PrintPriorityQueue();
    //add 3, 7, 2, 12, and 9
    queue.addPCB(table.getPCB(3));
    queue.addPCB(table.getPCB(7));
    queue.addPCB(table.getPCB(2));
    queue.addPCB(table.getPCB(12));
    queue.addPCB(table.getPCB(9));
    while(!queue.isEmpty())
    {
        //remove one and print the queue while not empty
        auto block = queue.removePCB();
        block->state = processState::RUNNING;
        queue.PrintPriorityQueue();
    }
}

void test2(PCB_Table& table, PriorityQueuePCB& queue)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rand(seed);
    auto KeysNotInQueue = table.getKeyVector();
    for(int i = 0; i < 10; i++)
    {
        //add ten random PCBs with random priorities
        unsigned pos = rand() % KeysNotInQueue.size();
        unsigned toSwap = KeysNotInQueue[pos];
        auto block = table.getPCB(toSwap);
        block->priority = rand() % 49 + 1;
        queue.addPCB(block);
        KeysNotInQueue[pos] = KeysNotInQueue[KeysNotInQueue.size() - 1];
        KeysNotInQueue.pop_back();
    }
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000000; i++)
    {
        if(rand() % 2 == 0)  //50:50 chance of remove or add
        { //add
            if(!KeysNotInQueue.empty())
            {
                //swap a random key with the one at the end and pop_back
                unsigned pos = rand() % KeysNotInQueue.size();
                unsigned toSwap = KeysNotInQueue[pos];
                auto block = table.getPCB(toSwap);
                block->priority = rand() % 49 + 1;
                queue.addPCB(block);
                KeysNotInQueue[pos] = KeysNotInQueue[KeysNotInQueue.size() - 1];
                KeysNotInQueue.pop_back();
            }
            else continue; //vector is empty, continue
        } 
        else
        { //remove from queue, add to list not in queue
            if(!queue.isEmpty())
            {
               auto block = queue.removePCB();
               block->state = processState::RUNNING;
               KeysNotInQueue.push_back(block->ID);
            }
            else continue; //queue is empty, continue
        }
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    queue.PrintPriorityQueue();
    std::cout << "This took " << duration << " microseconds" << std::endl;

}


int main()
{
    PCB_Table table{100};
    PriorityQueuePCB queue;
    try
    {
        for(unsigned i = 1; i <= 20; i++)
        {
            //auto block = createPCB(processState::NEW, i, i % 50 + 1);
            table.addNewPCB(processState::NEW, i, i % 50 + 1);
        }
        test1(table, queue);
        test2(table, queue);
        
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