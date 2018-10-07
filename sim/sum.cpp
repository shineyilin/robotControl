#include "sum.h"


namespace sim {

sum::sum(double init_value)
{
    this->init_value = init_value;
    this->out_value  = this->init_value;
}

void sum::setInitValue(double init_value)
{
    this->init_value = init_value;
    this->out_value += this->init_value;
}

void sum::addValue(double value)
{
    this->out_value += value;
}

void sum::minusValue(double value)
{
    this->out_value -= value;
}

double sum::getOutValue()
{
    return this->out_value;
}

void sum::reset()
{
    this->out_value = 0;
}

void sum::show()
{
    print("[sum]:");
    println(this->out_value);
}


} //end of namespace sim
