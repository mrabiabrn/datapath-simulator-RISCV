#include "Alu.h"

Alu::Alu(){}

Alu::Alu(int input_1, int input_2, int operation)
{
    setInput(input_1, input_2);
    setOperation(operation);
}


void Alu::setInput(int input_1, int input_2)
{
    setInput_1(input_1);
    setInput_2(input_2);
}

void Alu::setOperation(int operation)
{
    if(operation>3 || operation<0)
        return;
    this->operation = operation;
}

void Alu::setInput_1(int input_1){
    this->input_1 = input_1;
}

void Alu::setInput_2(int input_2){
    this->input_2 = input_2;
}
    
int Alu::getOutput(){
/*
    if(this->input_1 == nullptr || this->input_2 == nullptr){
        return nullptr;
    }
*/
/*
add->0
sub->1
and->2 
or ->3
*/
    if(this->operation == 0){
        return this->input_1 + this->input_2;
    }
    else if(this->operation == 1){
        return this->input_1 - this->input_2;
    }
    else if(this->operation == 2){
        return this->input_1 & this->input_2;
    }
    else if(this->operation == 3){
        return this->input_1 | this->input_2;
    }
    return 0;
}

bool Alu::getZero(){
    if(getOutput() == 0){
        return true;
    }
    return false;
}

int Alu::getOutput(int operation){
    setOperation(operation);
    return getOutput();
}

int Alu::getOutput(int input_1,int input_2, int operation){
    setInput(input_1,input_2);
    setOperation(operation);
    return getOutput();
}