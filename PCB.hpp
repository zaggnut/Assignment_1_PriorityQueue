/*
    Main C++ file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/01/18
    Last Update By: Michael Lingo

*/

//using an enum because its more efficient than using a string
enum class processState
{
    NEW, READY, RUNNING, WAITING, TERMINATED,
};


struct ProcessControlBlock
{
    processState state;
    unsigned ID;
};