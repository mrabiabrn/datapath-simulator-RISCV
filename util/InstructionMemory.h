#ifndef INS_MEM_H
#define INS_MEM_H

#include "RegisterFile.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class InstructionMemory {

	private:
	RegisterFile* PC;
	vector<vector<string>> instructions;
	map<string, int> labels;
	
	public:

	InstructionMemory(string filePath, RegisterFile* PC);
	void readInstruction(vector<string>& inst);
	int getInstructionNum();
	
};

#endif

