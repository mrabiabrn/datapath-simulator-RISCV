#ifndef MUX_H
#define MUX_H
 
class Mux
{

private:
    /*
    *   input_1: First input of the Mux
    *   input_2: Second input of the Mux
    *   select: Control signals which selects between input_1 and input_2
    */
    long input_1;
    long input_2;
    bool select;
 
public:
    Mux(long input_1, long input_2, bool select);
    Mux(long input_1, long input_2);
    Mux();
    // Sets the input_1
    void setInput_1(long input_1);
    // Sets the input_2
    void setInput_2(long input_2);
    // Sets the inputs
    void setInput(long input_1, long input_2);
    // Sets the select
    void setSelect(bool select);
    /*
    *  Returns the selected Mux input.
    *  if select is 0 input_1 is selected, otherwise input_2.
    */
    int getOutput();
    // Sets the select and returns the selected Mux input.
    int getOutput(bool select);
    // Sets the select, input_1 and input_2 and returns the selected Mux input.
    int getOutput(long input_1,long input_2, bool select);
 
};
 
#endif
