#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <vector>

using namespace std;

class RegisterFile {

	private:
	vector<int> registers;	
	vector<int> temp;
	bool regWrite;
	
	public:
	RegisterFile(int size, bool regWrite);			// regWrite = 1 when it is not the regfile
	void update();							// pass temp values to registers
	void setRegWrite(bool regWrite);						
	void getReg(int& reg1, int indx1);
	void getReg(int& reg1, int& reg2, int indx1, int indx2);
	void setReg(int regIndx, int data);				// change the element at the given indx
	
	
};

#endif


