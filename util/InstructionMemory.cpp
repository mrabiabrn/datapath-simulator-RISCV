#include "InstructionMemory.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// TODO: HANDLE INVALID INPUTS??

/*
 * 	reference : https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
 *
 */
InstructionMemory::InstructionMemory(string filePath) { 
	
	ifstream file("input.txt");
	string line;
	while(getline(file, line)) {
	
		if(line.size() > 0) {
	
		vector<string> instruction; //(4,"");

		istringstream str(line);
		string token;
		size_t position;
	
		while(str >> token) {
			
			while((position = token.find(","))!= std::string::npos || (position = token.find("("))!= std::string::npos 
										 || (position = token.find(")"))!= std::string::npos) {
				instruction.push_back(token.substr(0,position));
				token = token.substr(position+1);
				
			}
			
			if(!token.empty()) 
				instruction.push_back(token);
		}
	
		(this->instructions).push_back(instruction);
		
		}		
	
	}
	
	
}

