#include "Mux.h"

Mux::Mux(int input_1, int input_2, bool select)
{
    setInput(input_1, input_2);
    setSelect(select);
}

Mux::Mux(int input_1, int input_2t)
{
    setInput(input_1, input_2);
}

Mux::Mux(){}

void Mux::setInput(int input_1, int input_2)
{
    setInput_1(input_1);
    setInput_2(input_2);
}

void Mux::setSelect(bool select)
{
    this->select = select;
}

void Mux::setInput_1(int input_1){
    this->input_1 = input_1;
}

void Mux::setInput_2(int input_2){
    this->input_2 = input_2;
}
    
int Mux::getOutput(){

/*
    if(this->input_1 == nullptr || this->input_2 == nullptr){
        return nullptr;
    }
*/
    if(this->select){
        return input_2;
    }
    return input_1;
}

int Mux::getOutput(bool select){
    setSelect(select);
    return getOutput();
}

int Mux::getOutput(int input_1,int input_2, bool select){
    setInput(input_1,input_2);
    setSelect(select);
    return getOutput();
}