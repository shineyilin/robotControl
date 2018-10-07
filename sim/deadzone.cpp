#include "deadzone.h"

deadzone::deadzone(double up_limit, double bottom_limit)
{
    this->up_limit      = up_limit;
    this->bottom_limit  = bottom_limit;
}

void deadzone::setUpLimit(double up_limit)
{
    if (up_limit > this->bottom_limit)
    {
        this->up_limit = up_limit;
    }
    else
    {
        println("Error: up limit value less then bottom value!");
    }
}

void deadzone::setBottomLimit(double bottom_limit)
{
    if (bottom_limit < this->up_limit)
    {
        this->bottom_limit = bottom_limit;
    }
    else
    {
        println("Error: bottom limit value large then up value!");
    }
}

void deadzone::inputValue(double input_value)
{
    if (input_value > this->up_limit || input_value < this->bottom_limit )
    {
        this->out_value = input_value;
    }
    else
    {
        this->out_value = 0;
    }
}

double deadzone::getOutValue()
{
    return this->out_value;
}

void deadzone::show()
{
    print("[deadzone]:");
    println(this->out_value);
}
