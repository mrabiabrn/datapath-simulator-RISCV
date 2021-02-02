#include "RegisterFile.h"
#include <vector>

/*
 * Default value for registers -> 0
 * regWrite = 0 means the constructed object is Register File
 *
 */
RegisterFile::RegisterFile(int size, bool regWrite) { 
	
	(this->registers).resize(size,0);
	(this->temp).resize(size,0);
	 this->regWrite = regWrite;
	
}

/*
 * Write calculated values which has been stored in temp, to registers vector at the rising edge...
 *
 */
void RegisterFile::update() {

	this->registers = this->temp;
	
}

void RegisterFile::setRegWrite(bool regWrite) {

	this->regWrite = regWrite;

}

void RegisterFile::getReg(int& reg1, int indx1) {

	reg1 = this->registers[indx1];
	
}

void RegisterFile::getReg(int& reg1, int& reg2, int indx1, int indx2) {

	getReg(reg1,indx1); 
	getReg(reg2,indx2); 
}

// Writing to register file also in rising edge...Writing to temp no problem?!
void RegisterFile::setReg(int regIndx, int data){

	if(this->regWrite)
		this->temp[regIndx] = data;	

}




