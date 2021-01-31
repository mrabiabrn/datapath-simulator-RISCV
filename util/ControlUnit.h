#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <string>

using namespace std;

class ControlUnit {

	private:
	string operation;
	bool regWrite = 0;
	bool aluSrc = 0;		// 1 when second operand is an imm value, 0 otherwise
	bool memRead = 0;
	bool memWrite = 0;
	bool memToReg = 0;
	bool pcSrc = 0; 		// 0 when PC+4, 1 otherwise
	int aluOp;
	
	public:
	
	ControlUnit(string operation);
	
	void setOperation(string operation);	
	
	bool getRegWrite();
	bool getAluSrc();
	bool getMemRead();
	bool getMemWrite();
	bool getMemToReg();
	bool getPcSrc();
	int getAluOp();
	
	
	
};

#endif

