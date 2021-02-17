#include "Alu.h"

Alu::Alu(){}

/*
*   input_1: First input of the Alu
*   input_2: Second input of the Alu
*   operation: Operation to be performed on the Alu
*/
Alu::Alu(long input_1, long input_2, int operation)
{
    setInput(input_1, input_2);
    setOperation(operation);
}

/*
*   Sets the inputs
*   input_1: First input of the Alu
*   input_2: Second input of the Alu
*/
void Alu::setInput(long input_1, long input_2)
{
    setInput_1(input_1);
    setInput_2(input_2);
}

/*
*   Sets the operation
*   operation: Operation to be performed on the Alu
*/
void Alu::setOperation(int operation)
{
    if(operation>3 || operation<0)
        return;
    this->operation = operation;
}

/*
*   Sets the input_1
*   input_1: First input of the Alu
*/
void Alu::setInput_1(long input_1){
    this->input_1 = input_1;
}

/*
*   Sets the input_2
*   input_2: Second input of the Alu
*/
void Alu::setInput_2(long input_2){
    this->input_2 = input_2;
}

/*
*   Returns the arithmetic result based on the input_1,input_2 and input_3
*/ 
long Alu::getOutput(){
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

/*
* Returns whether the result is zero
*/
bool Alu::getZero(){
    if(getOutput() == 0){
        return true;
    }
    return false;
}

/*
*   Sets the operation and returns the output
*/
long Alu::getOutput(int operation){
    setOperation(operation);
    return getOutput();
}

/*
*   Sets the operation, input_1, input_2 and returns the output
*/
long Alu::getOutput(long input_1,long input_2, int operation){
    setInput(input_1,input_2);
    setOperation(operation);
    return getOutput();
}