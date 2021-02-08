#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <string>
#include "RegisterFile.h"

using namespace std;

class ControlUnit {

	private:
	int operation;
	bool regWrite = 0;
	bool aluSrc = 0;		// 1 when second operand is an imm value, 0 otherwise
	bool memRead = 0;
	bool memWrite = 0;
	bool memToReg = 0;
	bool pcSrc = 0; 		// 0 when PC+4, 1 otherwise
	int aluOp;
	
	public:

	
	void setOperation(int operation);	
	
	bool getRegWrite();
	bool getAluSrc();
	bool getMemRead();
	bool getMemWrite();
	bool getMemToReg();
	bool getPcSrc();
	int getAluOp();
	void fillReg(RegisterFile* regs, int idx);
	
	
	
};

#endif
