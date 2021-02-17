#include "Mux.h"

/*
*   input_1: First input of the Mux
*   input_2: Second input of the Mux
*   select: Control signals which selects between input_1 and input_2
*/
Mux::Mux(long input_1, long input_2, bool select)
{
    setInput(input_1, input_2);
    setSelect(select);
}

/*
*   Sets the inputs
*   input_1: First input of the Mux
*   input_2: Second input of the Mux
*/
Mux::Mux(long input_1, long input_2t)
{
    setInput(input_1, input_2);
}

Mux::Mux(){}

/*
*   Sets the inputs
*   input_1: First input of the Mux
*   input_2: Second input of the Mux
*/
void Mux::setInput(long input_1, long input_2)
{
    setInput_1(input_1);
    setInput_2(input_2);
}

/*
*   Sets the select
*   select: Control signal, if 0 input_1 is selected, otherwise input_2.
*/
void Mux::setSelect(bool select)
{
    this->select = select;
}


/*
*   Sets the input_1
*   input_1: First input of the Mux
*/
void Mux::setInput_1(long input_1){
    this->input_1 = input_1;
}

/*
*   Sets the input_2
*   input_2: Second input of the Mux
*/
void Mux::setInput_2(long input_2){
    this->input_2 = input_2;
}

/*
*  Returns the selected Mux input.
*  if select is 0 input_1 is selected, otherwise input_2.
*/   
int Mux::getOutput(){

    if(this->select){
        return input_2;
    }
    return input_1;
}

/*
*  Sets the select and returns the selected Mux input.
*/ 
int Mux::getOutput(bool select){
    setSelect(select);
    return getOutput();
}

/*
*  Sets the select, input_1 and input_2 and returns the selected Mux input.
*/ 
int Mux::getOutput(long input_1,long input_2, bool select){
    setInput(input_1,input_2);
    setSelect(select);
    return getOutput();
}
