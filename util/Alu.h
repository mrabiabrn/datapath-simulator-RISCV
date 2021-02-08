#ifndef ALU_H
#define ALU_H

class Alu
{
private:
    int input_1;
    int input_2;
    int operation;
 
public:
    Alu(int input_1, int input_2, int operation);
    Alu();
 
    void setInput_1(int input_1);
    void setInput_2(int input_2);
    void setInput(int input_1, int input_2);
    void setOperation(int operation);

    int getOutput();
    int getOutput(int operation);
    int getOutput(int input_1,int input_2, int operation);
    bool getZero();
 
};
 
#endif