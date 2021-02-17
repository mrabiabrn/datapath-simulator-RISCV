#ifndef INS_MEM_H
#define INS_MEM_H

#include "RegisterFile.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class InstructionMemory {

	private:
	// Pointer to the Program Counter
	RegisterFile* PC;
	// Vector to store instructions
	vector<vector<string>> instructions;
	// label-PC of the label pair
	map<string, int> labels;
	
	public:
	/*
 	*	filePath: Path of the instructions input file
 	*	PC: Pointer to the PC object
 	*/
	InstructionMemory(string filePath, RegisterFile* PC);
	/*
	* Returns the instruction for the current PC.
	* vector<string>& inst: Takes parameter vector as pass by reference and updates it.
	*/
	void readInstruction(vector<string>& inst);
	// Returns the instruction numbers without labels.
	int getInstructionNum();
	
};

#endif

