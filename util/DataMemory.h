#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <map>
#include <string>

using namespace std;

class DataMemory
{
private:
    std::map<int,long> dataMap;
    bool memRead = false;
    bool memWrite = false;
 
public:

    DataMemory(string filePath);
    
    void setMemRead(bool memRead);
    void setMemWrite(bool memWrite);

    long read(int address);
    void write(int address, long data);
};
 
#endif
