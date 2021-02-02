#include <iostream>
#include "./util/RegisterFile.h"
#include "./util/ControlUnit.h"
#include "./util/Alu.h"
#include "./util/DataMemory.h"
#include "./util/Mux.h"
#include "./util/InstructionMemory.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

int main() {

	/*
	RegisterFile r = RegisterFile(32,true);
	r.writeReg(1,3);
	r.writeReg(2,4);
	r.writeReg(3,6);
	
	int reg1, reg2;
	
	r.update();
	r.readReg(reg1,reg2,1,2);
	
	cout << reg1 << " " << reg2 << endl;
	
	ControlUnit c = ControlUnit("ld");
	cout << c.getRegWrite() << " " << c.getMemRead() << endl;*/
	
	/*
	InstructionMemory im = InstructionMemory("input.txt");
	for(int i = 0; i < im.instructions.size(); i++) {
	
		for (int j = 0; j < 4; j++)
			cout<< im.instructions[i][j] << endl;
	
	}
	*/
	
	InstructionMemory im = InstructionMemory("input.txt");
	RegisterFile PC = RegisterFile(1,true);
	int clk = 0;
	
	int numInst = im.getInstructionNum();
	
	/*while(PC <= numInst) {
	
		//vector<string> curInst = im.readInstruction();
	
		
	
	
	}*/
	
	
		
	
	


 return 0;
 
}
