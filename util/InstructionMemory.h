#ifndef INS_MEM_H
#define INS_MEM_H

#include "RegisterFile.h"
#include <vector>
#include <string>

using namespace std;

class InstructionMemory {

	private:
	//vector<vector<string>> instructions;	
	RegisterFile* PC;
	
	public:
	vector<vector<string>> instructions;
	InstructionMemory(string filePath);
	//readInstruction(vector<string>& inst);
	//setPC();
	
};

#endif

