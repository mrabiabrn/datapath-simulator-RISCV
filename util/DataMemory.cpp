#include "DataMemory.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


using namespace std;

DataMemory::DataMemory(string filePath) {

	ifstream file(filePath);
	string line;
	int i = 0;
	
	getline(file, line);	// first line is header
	
	while(getline(file, line)) {
	
	if(line.size() > 0) {	// pass empty lines
	
		istringstream str(line);
		string token;
		size_t position;
	
		str >> token;
		int address = stoi(token);		// read first token in the line (address)
		str >> token;
		long data = stol(token);		// read second token in the line (data)
		
		this->dataMap[address] = data;	// no need for memWrite when writing at the beginning
		
	}
	
	}

	



}

void DataMemory::setMemRead(bool memRead)
{
    this->memRead = memRead;
}

void DataMemory::setMemWrite(bool memWrite)
{
    this->memWrite = memWrite;
}

long DataMemory::read(int address)
{
    if(this->memRead){
        std::map<int,long>::iterator it = this->dataMap.find(address) ;
        if (it == this->dataMap.end() )
        {
            return -1;
        }
        return it->second;
    }
    return -1;
}

void DataMemory::write(int address, long data){
    if(this->memWrite){
        this->dataMap[address] = data;
    }
}
