#ifndef MUX_H
#define MUX_H
 
class Mux
{
public:
    int input_1;
    int input_2;
    bool select;
 
public:
    Mux(int input_1, int input_2, bool select);
    Mux(int input_1, int input_2);
    Mux();
 
    void setInput_1(int input_1);
    void setInput_2(int input_2);
    void setInput(int input_1, int input_2);
    void setSelect(bool select);

    int getOutput();
    int getOutput(bool select);
    int getOutput(int input_1,int input_2, bool select);
 
};
 
#endif
