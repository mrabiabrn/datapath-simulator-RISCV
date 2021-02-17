#ifndef ALU_H
#define ALU_H

class Alu
{
private:
/*
*   input_1: First input of the Alu
*   input_2: Second input of the Alu
*   operation: Operation to be performed on the Alu
*/
    long input_1;
    long input_2;
    long operation;
   
 
public:
    /*
    *   input_1: First input of the Alu
    *   input_2: Second input of the Alu
    *   operation: Operation to be performed on the Alu
    */
    Alu(long input_1, long input_2, int operation);
    Alu();
    // Sets the input_1
    void setInput_1(long input_1);
    // Sets the input_2
    void setInput_2(long input_2);

    //Sets the inputs
    void setInput(long input_1, long input_2);
    // Sets the operation
    void setOperation(int operation);
    // Returns the arithmetic result based on the input_1,input_2 and input_3
    long getOutput();
    // Sets the operation and returns the output
    long getOutput(int operation);
    // Sets the operation, input_1, input_2 and returns the output
    long getOutput(long input_1,long input_2, int operation);
    // Returns whether the result is zero
    bool getZero();
 
};
 
#endif
