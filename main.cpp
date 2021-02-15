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
#include <map>

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
	map<string, int> instonum;
	instonum["add"] = 0;
	instonum["sub"] = 1;
	instonum["and"] = 2;
	instonum["or"] = 3;
	instonum["ld"] = 4;
	instonum["sd"] = 5;
	instonum["beq"] = 6;



	RegisterFile PC = RegisterFile(1, 1);
	InstructionMemory im = InstructionMemory("input.txt", &PC);
	RegisterFile registers = RegisterFile(32, 0);
	Alu alu = Alu();
	DataMemory dm = DataMemory();
	Mux aluMux = Mux();
	Mux pcMux = Mux();
	Mux writeMux = Mux();
	Alu adder = Alu(0,0,0);

	RegisterFile if_id = RegisterFile(5, 1);
	RegisterFile id_ex = RegisterFile(14, 1);
	RegisterFile ex_mem = RegisterFile(32, 1);
	RegisterFile mem_wb = RegisterFile(32, 1);

	ControlUnit control = ControlUnit();

	int clk = 0;
	
	registers.setRegWrite(true);
	registers.setReg(1,5);
	registers.setReg(2,10);
	registers.setReg(3,15);
	registers.update();
	
	for(int i= 0; i < 3; i++)
		cout << "x" << i+1 << " " << registers.getReg(i+1) << endl;
	
	cout << endl;
	

	while(PC.getReg(0)<im.getInstructionNum()*5){
		// IF
		vector<string> inst;
		im.readInstruction(inst);
		/*
		0 -> instruction add 0 sub 1 load 2 sd 3 beq 4
		1 -> regd add regd,reg1,reg2
		2 -> reg1
		3 -> reg2
		4 -> PC
		*
		* give 2 and 3 to alu
		*/
	//sd de offset regd
		if_id.setReg(0, instonum.find(inst[0])->second);
		
		int offset;
	
		if(inst[0] == "ld"){
			if_id.setReg(1, stoi(inst[1].substr(1)));	// rdest
			if_id.setReg(2, stoi(inst[3].substr(1))); 	// reg1
			if_id.setReg(5, stoi(inst[2])); 		// offset
			offset = stoi(inst[2]);
		}
		else if(inst[0] == "sd" ){
			if_id.setReg(5, stoi(inst[2]));	   	// offset
			if_id.setReg(2, stoi(inst[3].substr(1))); 	// reg2
			if_id.setReg(3, stoi(inst[1].substr(1))); 	// reg1
			offset = stoi(inst[1]);
			
		}
		else if(inst[0] == "beq"){
			if_id.setReg(5, stoi(inst[3]));		 // offset
			if_id.setReg(2, stoi(inst[2].substr(1)));	 // reg1
			if_id.setReg(3, stoi(inst[1].substr(1))); 	 // regd
			
		}
		else{
			if_id.setReg(1, stoi(inst[1].substr(1)));	// dest
			if_id.setReg(2, stoi(inst[2].substr(1)));	// reg1
			if_id.setReg(3, stoi(inst[3].substr(1)));	// reg2
			
		}

		
		if_id.setReg(4, PC.getReg(0));
		PC.setReg(0,PC.getReg(0)+1);		// PC+4	
		
		// ID
		/*
		0 -> instruction add 0 sub 1 load 2 sd 3 beq 4
		1 -> regd add regd,reg1,reg2  ld regd offset(reg1) -> offset reg2
		2 -> reg1
		3 -> reg2
		4 -> PC
		5 -> reg1 val
		6 -> reg2 val
		7 ->regWrite);
		8->aluSrc);
		9->memRead);
		10->memWrite);
		11->memToReg);
		12->pcSrc);
		13->aluOp);
		*/

		control.setOperation(if_id.getReg(0));
		id_ex.setReg(0, if_id.getReg(0));
		id_ex.setReg(1, if_id.getReg(1));
		id_ex.setReg(2, if_id.getReg(2));
		id_ex.setReg(3, if_id.getReg(3));
		id_ex.setReg(4, if_id.getReg(4));
		id_ex.setReg(5, registers.getReg(if_id.getReg(2))); // read reg1 value
		id_ex.setReg(6, registers.getReg(if_id.getReg(3))); // read reg2 value
		control.fillReg(&id_ex, 7);
		id_ex.setReg(14, if_id.getReg(5));	// offset
		
		// EX
		aluMux.setSelect(id_ex.getReg(8));
		aluMux.setInput_1(id_ex.getReg(6));
		aluMux.setInput_2(id_ex.getReg(14));	// get offset

		alu.setOperation(id_ex.getReg(13));
		alu.setInput(id_ex.getReg(5), aluMux.getOutput());
		
		adder.setInput(id_ex.getReg(4), id_ex.getReg(14));	// calculates the address for branch

		ex_mem.setReg(0, id_ex.getReg(0));
		ex_mem.setReg(1, id_ex.getReg(1));
		ex_mem.setReg(2, id_ex.getReg(2));
		ex_mem.setReg(3, id_ex.getReg(3));
		ex_mem.setReg(4, id_ex.getReg(4));
		ex_mem.setReg(5, alu.getOutput()); // read reg1
		ex_mem.setReg(6, alu.getZero());
		ex_mem.setReg(7, adder.getOutput());
		ex_mem.setReg(8, id_ex.getReg(6)); // read second
		
		for(int i= 0; i < 7; i++)
			ex_mem.setReg(i+9, id_ex.getReg(i+1));
		
		
		int branch;
		branch = ex_mem.getReg(6) & ex_mem.getReg(13);	// zero AND pcSrc
		
		
		dm.setMemWrite(ex_mem.getReg(11));
		dm.setMemRead(ex_mem.getReg(10));
	
		
		dm.write(ex_mem.getReg(5), ex_mem.getReg(8));
		
		mem_wb.setReg(0, ex_mem.getReg(0));
		mem_wb.setReg(1, ex_mem.getReg(1));
		mem_wb.setReg(2, ex_mem.getReg(2));
		mem_wb.setReg(3, ex_mem.getReg(3));
		mem_wb.setReg(4, ex_mem.getReg(4));
		mem_wb.setReg(5, dm.read(ex_mem.getReg(5))); // read this address
		mem_wb.setReg(6, ex_mem.getReg(5));	// address
		mem_wb.setReg(7, ex_mem.getReg(9));	// regWrite
		mem_wb.setReg(8, ex_mem.getReg(13));	// memToReg
		
		writeMux.setSelect(mem_wb.getReg(8));
		writeMux.setInput_1(mem_wb.getReg(6));
		writeMux.setInput_2(mem_wb.getReg(5));
		
		registers.setRegWrite(mem_wb.getReg(7));
		registers.setReg(mem_wb.getReg(1),writeMux.getOutput());
		
		
		registers.update();
		if_id.update();
		id_ex.update();
		ex_mem.update();
		mem_wb.update();
		PC.update();
		
		for(int i= 0; i < 3; i++)
		cout << "x" << i+1 << " " << registers.getReg(i+1) << endl;
		
		cout<<endl;
		
	

	}



	//int clk = 0;
	
	
	for(int i= 0; i < 3; i++)
		cout << "x" << i+1 << " " << registers.getReg(i+1) << endl;
	
	
		
	
	


 return 0;
 
}
