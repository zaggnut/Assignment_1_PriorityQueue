/*
    PCB Table header file, requires C++14
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/15/18
    Last Update By: Michael Lingo

*/
#ifndef PCB_TABLE_HPP //header guards
#define PCB_TABLE_HPP

#include "PCB.hpp"
#include <memory>
#include <unordered_map> //storing the table in an unordered map
#include <vector>        //storing all the keys in a vector improves getting a random process
#include <utility>       //for std::pair
#include <stdexcept>
#include <random>
#include <chrono>
#include <ext/bitmap_allocator.h> //uses a custom allocator in the gcc for better allocation efficiency

//stores refrences to process control blocks

class PCBKeyClass //a helper struct to allow removing the key from the key vector easier
{
protected:
  static __gnu_cxx::bitmap_allocator<PCBKeyClass> allocator;

public:
  unsigned long processVectorIndex;
  ProcessControlBlock *block;

  PCBKeyClass(unsigned long index_, ProcessControlBlock *block_)
  {
    processVectorIndex = index_;
    block = block_;
  }

  static void *operator new(std::size_t size)
  {
    return allocator._M_allocate_single_object();
  }
  static void operator delete(void *block)
  {
    allocator._M_deallocate_single_object((PCBKeyClass *)block);
  }
};

class InsertFailedException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "failed to insert, process with that ID already exits?";
  }
};

class ProcessNotFoundException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "A process control block with that ID was not found";
  }
};

class PCB_Table
{
protected:
  //map to hold the data
  std::unordered_map<PCB_ID_TYPE,
                     PCBKeyClass,
                     std::hash<PCB_ID_TYPE>,
                     std::equal_to<PCB_ID_TYPE>,
                     __gnu_cxx::bitmap_allocator<std::pair<const PCB_ID_TYPE, PCBKeyClass>>>
      ProcessMap;

  //for random number generation
  std::default_random_engine rand;

  //vector to hold all they keys, faster access for rng
  std::vector<PCB_ID_TYPE> keyVector;

public:
  //default constructor
  PCB_Table();

  //set an initial size
  PCB_Table(unsigned initialSize);

  ~PCB_Table();

  //returns the number of PCBs in the Table
  unsigned long size();

  //stores a process control block, throws exception if store unsuccessful
  void addNewPCB(ProcessControlBlock *process);
  void addNewPCB(processState state, PCB_ID_TYPE ID_, unsigned Priority);

  //returns a refrence to a process control block, throws exception if not found
  ProcessControlBlock *getPCB(PCB_ID_TYPE processID);

  const std::vector<PCB_ID_TYPE> &getKeyVector() const;

  //removes a specific PCB from the table
  ProcessControlBlock *removePCB(PCB_ID_TYPE processID);

  //removes and returns a random PCB from the table, throws an exception if there aren't any to remove
  ProcessControlBlock *removeRandomPCB();

  //clears the table, deallocates everything inside it as well
  void clear();
};

#endif //PCB_Table_HPP included