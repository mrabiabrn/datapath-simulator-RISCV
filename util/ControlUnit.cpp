#include "ControlUnit.h"
#include <string>
#include <iostream>

using namespace std;

/*
add->0, sub->1, and->2, or ->3
*/
void ControlUnit::setOperation(int operation){
	regWrite = 0;
	aluSrc = 0;		// 1 when second operand is an imm value, 0 otherwise
	memRead = 0;
	memWrite = 0;
	memToReg = 0;
	pcSrc = 0; 
	if(operation == 0) { 
		this->regWrite = true;
		this->aluOp = 0;
	}
	else if(operation == 1) {
		this->regWrite = true;
		this->aluOp = 1;
	}
	else if(operation == 2) {
		this->regWrite = true;
		this->aluOp = 2;
	}
	else if(operation == 3) {
		this->regWrite = true;
		this->aluOp = 3;
	}
	else if(operation == 4) {
		this->regWrite = this->aluSrc = this->memRead = true;
		this->aluOp = 0;
	}
	else if(operation == 5) {
		this->aluSrc = this->memWrite = true;
		this->aluOp = 0;
	}
	else if(operation == 6) {
		this->aluOp = 1;
		// this->pcSrc = 1;
	}


}	


bool ControlUnit::getRegWrite() {

	return (this->regWrite);	
	
}

bool ControlUnit::getAluSrc() {

	return (this->aluSrc);	
	
}
	
bool ControlUnit::getMemRead() {

	return (this->memRead);	
	
}

bool ControlUnit::getMemWrite() {

	return (this->memWrite);	
	
}

bool ControlUnit::getMemToReg() {

	return (this->memToReg);	
	
}

bool ControlUnit::getPcSrc() {

	return (this->pcSrc);	
	
}

int ControlUnit::getAluOp() {

	return (this->aluOp);	
	
}
	
	bool regWrite = 0;
	bool aluSrc = 0;		// 1 when second operand is an imm value, 0 otherwise
	bool memRead = 0;
	bool memWrite = 0;
	bool memToReg = 0;
	bool pcSrc = 0; 		// 0 when PC+4, 1 otherwise
	int aluOp;


void ControlUnit::fillReg(RegisterFile* regs, int idx){
	regs->setReg(idx,this->regWrite);
	regs->setReg(idx+1,this->aluSrc);
	regs->setReg(idx+2,this->memRead);
	regs->setReg(idx+3,this->memWrite);
	regs->setReg(idx+4,this->memToReg);
	regs->setReg(idx+5,this->pcSrc);
	regs->setReg(idx+6,this->aluOp);
}
