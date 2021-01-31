#include "ControlUnit.h"
#include <string>
#include <iostream>

using namespace std;

ControlUnit::ControlUnit(string operation) { 
	
	this->setOperation(operation);
	
}

/*
add->0, sub->1, and->2, or ->3
*/
void ControlUnit::setOperation(string operation){

	if(!operation.compare("add")) {
		this->regWrite = true;
		this->aluOp = 0;
	}
	else if(!operation.compare("sub")) {
		this->regWrite = true;
		this->aluOp = 1;
	}
	else if(!operation.compare("and")) {
		this->regWrite = true;
		this->aluOp = 2;
	}
	else if(!operation.compare("or")) {
		this->regWrite = true;
		this->aluOp = 3;
	}
	else if(!operation.compare("ld")) {
		this->regWrite = this->aluSrc = this->memRead = this->aluOp = true;
		this->aluOp = 0;
	}
	else if(!operation.compare("sd")) {
		this->aluSrc = this->memWrite = true;
		this->aluOp = 0;
	}
	else if(!operation.compare("beq")) {
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
	

