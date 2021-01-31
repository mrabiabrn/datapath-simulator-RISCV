#ifndef MUX_H
#define MUX_H
 
class Mux
{
private:
    int* input_1;
    int* input_2;
    int select;
 
public:
    Mux(int* input_1, int* input_1, int select);
    Mux(int* input_1, int* input_1);
    Mux();
 
    void setInput_1(int* input_1);
    void setInput_2(int* input_2);
    void setInput(int* input_1, int* input_2);
    void setSelect(int select);

    int* getOutput();
    int* getOutput(int select);
    int* getOutput(int* input_1,int* input_2, int select);
 
};
 
#endif