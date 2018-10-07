#include "sturation.h"

sturation::sturation(double up_border, double bottom_border)
{
    this->up_border = up_border;
    this->bottom_border = bottom_border;
}

void sturation::inputValue(double input_value)
{
    if (input_value > this->up_border)
    {
        this->out_value = this->up_border;
    }
    else if (input_value < this->bottom_border)
    {
        this->out_value = this->bottom_border;
    }
    else
    {
        this->out_value = input_value;
    }
}

void sturation::setUpBorder(double up_border)
{
    if (up_border > this->bottom_border )
    {
        this->up_border = up_border;
    }
    else
    {
        println("Error: up border value small then bottom value!!!");
    }
}

void sturation::setBottomBorder(double bottom_border)
{
    if ( bottom_border < this->up_border )
    {
        this->bottom_border = bottom_border;
    }
    else
    {
        println("Error: bottom border value small then up value!!!");
    }
}

double sturation::getOutValue()
{
    return this->out_value;
}

void sturation::show()
{
    print("[sturation]:");
    println(this->out_value);
}
