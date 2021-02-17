#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <map>
#include <string>

using namespace std;

class DataMemory
{
private:
    // Map that stores address-data pairs
    std::map<int,long> dataMap;
    // Control signals
    bool memRead = false;
    bool memWrite = false;
 
public:

    DataMemory(string filePath);
    // Sets the control signal memRead
    void setMemRead(bool memRead);
    // Sets the control signal memWrite
    void setMemWrite(bool memWrite);
    // Prints the saved data addresses and their data value.
    void printData();
    // Given an address returns the data on that memory address.
    long read(int address);
    // Given an address and a data writes the data to that memory address. 
    void write(int address, long data);
};
 
#endif
