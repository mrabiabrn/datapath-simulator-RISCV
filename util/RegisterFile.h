#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <vector>

using namespace std;

class RegisterFile {

	vector<int> registers;	
	vector<int> temps;
	
	public:
	RegisterFile(int size);
	void readRegs(int& reg1, int& reg2, int indx1, int indx2);
	void writeReg(int regIndx, int data);
	
};

#endif


