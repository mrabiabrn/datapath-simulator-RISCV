#include "RegisterFile.h"
#include <vector>

RegisterFile::RegisterFile() { 
	
	(this->registers).push_back(0);

}

void RegisterFile::readRegs(int& reg1, int& reg2, int indx1, int indx2) {

	reg1 = this->registers[indx1];
	reg2 = this->registers[indx2];
	
}

void RegisterFile::writeReg(int regIndx, int data){

	this->registers[regIndx] = data;	

}
