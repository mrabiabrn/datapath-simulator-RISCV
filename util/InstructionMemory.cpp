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
InstructionMemory::InstructionMemory(string filePath, RegisterFile* PC) { 

	//PC = 0;
	this->PC = PC;
	ifstream file("input.txt");
	string line;
	int i = 0;
	while(getline(file, line)) {
	
		if(line.size() > 0) {
		
		vector<string> instruction; //(4,"");  x1 x2 inst-pc

		istringstream str(line);
		string token;
		size_t position;
	
		while(str >> token) {
			
			while((position = token.find(","))!= std::string::npos || (position = token.find("("))!= std::string::npos 
											|| (position = token.find(")"))!= std::string::npos) {
				if(!token.substr(0,position).empty())
					instruction.push_back(token.substr(0,position));

				token = token.substr(position+1);	
			}
			
			// extract labels.... <labelName>:
			if((position = token.find(":"))!= std::string::npos) {
				token = token.substr(0,position);
				(this->labels).insert(pair<string,int>(token,i));	
			}
			
			if(!token.empty()) 
				instruction.push_back(token);

		}
	
		(this->instructions).push_back(instruction);
		
		i++;
		}		
	
	}
	
	
}



void InstructionMemory::readInstruction(vector<string>& inst) {
	// Son instruction label olmamalı
	while(true){
		long reg = 0;
		this->PC->getReg(reg,0);
		inst = (this->instructions)[reg];
		if(inst.size() == 1){
			this->PC->setReg(0,reg+1);
			continue;
		}
		if(!inst[0].compare("beq")){
			inst[3] = labels.find(inst[3])->second - PC->getReg(0);
		}

		break;
	}
	
}



int InstructionMemory::getInstructionNum() {

	return (this->instructions).size();

}
	

