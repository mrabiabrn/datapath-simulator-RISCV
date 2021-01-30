#include <iostream>
#include "RegisterFile.h"

using namespace std;

int main() {


	RegisterFile r;
	r.writeReg(1,3);
	r.writeReg(2,4);
	r.writeReg(3,6);
	
	int reg1, reg2;
	
	r.readRegs(reg1,reg2,1,0);
	
	cout << reg1 << " " << reg2 << endl;


 return 0;
 
}
