#include "gain.h"
namespace sim {

gain::gain(double gain_value)
{
    this->gain_value = gain_value;
}

void gain::setGainValue(double gain_value)
{
    this->gain_value = gain_value;
}

void gain::inputValue(double input_value)
{
    this->out_value = input_value * this->gain_value;
}

double gain::getOutValue()
{
    return this->out_value;
}

void gain::show()
{
    print("[gain]:");
    println(this->out_value);
}


}//end of namespace sim
