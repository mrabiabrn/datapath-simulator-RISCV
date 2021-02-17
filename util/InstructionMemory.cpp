#include "InstructionMemory.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// TODO: HANDLE INVALID INPUTS??

/*
 * 	reference : https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
 *	filePath: Path of the instructions input file
 *	PC: Pointer to the PC object
 */
InstructionMemory::InstructionMemory(string filePath, RegisterFile* PC) { 

	//PC = 0;
	this->PC = PC;
	ifstream file(filePath);
	string line;
	int i = 0;
	// Read all instructions and store them in a vector. When an instruction is read, it is sent from this vector.
	while(getline(file, line)) {
	
		if(line.size() > 0) {
		
		vector<string> instruction; //(4,"");  x1 x2 inst-pc

		istringstream str(line);
		string token;
		size_t position;
	
		while(str >> token) {
			// Parse the instruction
			while((position = token.find(","))!= std::string::npos || (position = token.find("("))!= std::string::npos 
											|| (position = token.find(")"))!= std::string::npos) {
				if(!token.substr(0,position).empty())
					instruction.push_back(token.substr(0,position));

				token = token.substr(position+1);	
			}
			
			// extract labels.... <labelName>:
			// Labels are added to the labels map with its PC to extract on beq instructions
			if((position = token.find(":"))!= std::string::npos) {
				token = token.substr(0,position);
				(this->labels).insert(pair<string,int>(token,i));	
			}
			// Unless an empty token add to instruction
			if(!token.empty()) 
				instruction.push_back(token);

		}
	
		(this->instructions).push_back(instruction);
		
		i++;
		}		
	
	}
	
	
}

/*
* Returns the instruction for the current PC.
* vector<string>& inst: Takes parameter vector as pass by reference and updates it.
*/
void InstructionMemory::readInstruction(vector<string>& inst) {

	while(true){
		// If PC is bigger than the instruction number, return a nop instruction
		// Required to make sure the last instruction gets to the WB stage
		if(this->PC->getReg(0)>=this->instructions.size()){
			
			inst.push_back( "nop");
			inst.push_back("x0");
			inst.push_back("x0");
			inst.push_back("x0");
			break;
		}
		long reg = 0;
		this->PC->getReg(reg,0);
		inst = (this->instructions)[reg];
		// If next instruction is a label, until a non-label instruction is found, PC is incremented.
		// Only valid instructions are returned as instructions.
		if(inst.size() == 1){
			this->PC->setReg(0,reg+1);
			this->PC->update();
			continue;
		}
		// On beq instruction, the offset to the current PC is returned instead of the label name.
		if(!inst[0].compare("beq")){
			inst[3] = to_string(labels.find(inst[3])->second - PC->getReg(0));
		}

		break;
	}
	
}


// Returns the instruction numbers without labels.
int InstructionMemory::getInstructionNum() {
	
	return (this->instructions).size()-this->labels.size();

}
	

