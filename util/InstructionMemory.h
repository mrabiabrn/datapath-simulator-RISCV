#ifndef INS_MEM_H
#define INS_MEM_H

#include "RegisterFile.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class InstructionMemory {

	private:
	vector<vector<string>> instructions;
	map<string, int> labels;
	int PC;
	
	public:

	InstructionMemory(string filePath);
	void readInstruction(vector<string>& inst);
	void setPC(int address);
	int getInstructionNum();
	
};

#endif

