#include "RegisterFile.h"
#include <vector>

/*
 * 	Default value for registers -> 0
 * 	regWrite = 0 means the constructed object is Register File
 *	temp is the temporary storage for the registers, values on temp are written to registers on update()
 */
RegisterFile::RegisterFile(int size, bool regWrite) { 
	
	(this->registers).resize(size,0);
	(this->temp).resize(size,0);
	this->regWrite = regWrite;
	
}

/*
 * 	Write calculated values which has been stored in temp, to registers vector at the rising edge.
 */
void RegisterFile::update() {
	this->registers = this->temp;	
}

// Sets the control signal regWrite which must be true to write a value.
void RegisterFile::setRegWrite(bool regWrite) {

	this->regWrite = regWrite;

}
/*
* Returns a registers value given its index
* reg1: Pass by reference long to write the register value
* indx1: Register index
*/
void RegisterFile::getReg(long& reg1, int indx1) {

	reg1 = this->registers[indx1];
	
}

/*
* Returns a registers value given its index
* indx1: Register index
*/
long RegisterFile::getReg(int indx1) {

	if(indx1 >= this->registers.size())
		return 0;

	return this->registers[indx1];
	
}

/*
* Returns 2 register values value given its index
* reg1: Pass by reference long to write the register value_1
* indx1: Register index_1
* reg2: Pass by reference long to write the register value_2
* indx2: Register index_2
*/
void RegisterFile::getReg(long& reg1, long& reg2, int indx1, int indx2) {

	getReg(reg1,indx1); 
	getReg(reg2,indx2); 
}

/*
* Writes a given value to given index
* Only written when regWrite is true.
* Written to temp registers, permanently written on update()
* regIndx: Index of the register
* data: Data to be written
*/
void RegisterFile::setReg(int regIndx, long data){
	if(this->regWrite)
		this->temp[regIndx] = data;	
}




