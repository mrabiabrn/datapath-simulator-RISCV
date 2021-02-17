#include "DataMemory.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


using namespace std;
/*
*	Stores the memory adress-data pairs in the dataMap map.
*	filePath: Path of the file with the data input
*/
DataMemory::DataMemory(string filePath) {

	ifstream file(filePath);
	string line;
	int i = 0;
	
	getline(file, line);	// first line is header
	
	while(getline(file, line)) {
	
	if(line.size() > 0) {	// pass empty lines
	
		istringstream str(line);
		string token;
	
		str >> token;
		int address = stoi(token);		// read first token in the line (address)
		str >> token;
		long data = stol(token);		// read second token in the line (data)
		
		this->dataMap[address] = data;	// no need for memWrite when writing at the beginning
		
	}
	
	}
}

// Sets the control signal memRead which must be true to read a value.
void DataMemory::setMemRead(bool memRead)
{
    this->memRead = memRead;
}
// Sets the control signal memWrite which must be true to write a value.
void DataMemory::setMemWrite(bool memWrite)
{
    this->memWrite = memWrite;
}

/* 
* 	Given an address returns the data on that memory address. If no data was recorded for the address returns -1.
* 	If memRead is false, -1 is returned.
*/
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

/* 
* 	Given an address and a data writes the data to that memory address. 
* 	If memWrite is false, data is not written.
*/
void DataMemory::write(int address, long data){
    if(this->memWrite){
        this->dataMap[address] = data;
    }
}

/*
*	Prints the saved data addresses and their data value.
*/
void DataMemory::printData(){
	int i=1;
	for (std::map<int,long>::iterator it=(this->dataMap).begin(); it!=(this->dataMap).end(); ++it){
    	std::cout <<"mem("<< it->first << ") = " << it->second << (i%3==0?'\n':'\t');
		i++;
	}
	
}
