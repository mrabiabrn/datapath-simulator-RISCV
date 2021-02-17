#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <string>
#include "RegisterFile.h"

using namespace std;

class ControlUnit {

	private:
	// Instruction whose signals will be calculated
	// add->0, sub->1, and->2, or ->3,	ld->4,	sd->5,	beq->6
	int operation;
	bool regWrite = 0;
	bool aluSrc = 0;		// 1 when second operand is an imm value, 0 otherwise
	bool memRead = 0;
	bool memWrite = 0;
	bool memToReg = 0;
	bool pcSrc = 0; 		// 0 when PC+4, 1 otherwise
	int aluOp;
	
	public:

	/*
	add->0, sub->1, and->2, or ->3,	ld->4,	sd->5,	beq->6
	Sets the control signals according to the given instruction
	*/
	void setOperation(int operation);	
	// Next 7 functions returns the control signal
	bool getRegWrite();
	bool getAluSrc();
	bool getMemRead();
	bool getMemWrite();
	bool getMemToReg();
	bool getPcSrc();
	int getAluOp();
	// Given a register file and in index, fills the control values to the register file starting from the index(inclusive).
	void fillReg(RegisterFile* regs, int idx);
	
	
	
};

#endif

