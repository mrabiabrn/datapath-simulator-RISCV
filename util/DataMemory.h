#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <map>
class DataMemory
{
private:
    std::map<int,int> dataMap;
    bool memRead;
    bool memWrite;
 
public:

 
    void setMemRead(bool memRead);
    void setMemWrite(bool memWrite);

    int read(int address);
    void write(int address, int data);
};
 
#endif