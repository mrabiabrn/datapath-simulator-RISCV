#include "DataMemory.h"


void DataMemory::setMemRead(bool memRead)
{
    this->memRead = memRead;
}

void DataMemory::setMemWrite(bool memWrite)
{
    this->memWrite = memWrite;
}

int DataMemory::read(int address)
{
    if(this->memRead){
        std::map<int,int>::iterator it = this->dataMap.find(address) ;
        if (it == this->dataMap.end() )
        {
            return -1;
        }
        return it->second;
    }
    return -1;
}

void DataMemory::write(int address, int data){
    if(this->memWrite){
        this->dataMap[address] = data;
    }
}