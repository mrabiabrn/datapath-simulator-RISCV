#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <vector>

using namespace std;

class RegisterFile {

	private:
	// Main storage for registers
	vector<long> registers;	
	// The temporary storage for the registers, values on temp are written to registers on update()
	vector<long> temp;
	// Control signal
	bool regWrite;
	
	public:
	RegisterFile(int size, bool regWrite);			// regWrite = 1 when it is not the regfile
	// Write calculated values which has been stored in temp, to registers vector at the rising edge.
	void update();							
	// Sets the control signal regWrite which must be true to write a value.
	void setRegWrite(bool regWrite);	
	// Returns a registers value given its index					
	void getReg(long& reg1, int indx1);
	// Returns a registers value given its index
	long getReg(int indx1);
	// Returns 2 register values value given its index
	void getReg(long& reg1, long& reg2, int indx1, int indx2);
	// Writes a given value to given index
	void setReg(int regIndx, long data);				
	
	
};

#endif


