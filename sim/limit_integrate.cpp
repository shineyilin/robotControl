#include "limit_integrate.h"

limit_integrate::limit_integrate(double up_limit, double bottom_limit)
{

}

void limit_integrate::inputValue(double input_value)
{
    this->bef_value   = this->out_value;
    this->out_value  += input_value * this->step_time;
    if (this->out_value > this->up_limit)
    {
        this->out_value = this->up_limit;
    }
    else if(this->out_value < this->bottom_limit)
    {
        this->out_value = bottom_limit;
    }

    this->total_time += this->step_time;
}

void limit_integrate::setUpLimit(double up_limit)
{
    if (up_limit > this->bottom_limit)
    {
        this->up_limit = up_limit;
    }
    else
    {
        println("Error: up limit data less then bottom data!");
    }
}

void limit_integrate::setBottomLimit(double bottom_limit)
{
    if(bottom_limit < this->up_limit)
    {
        this->bef_value = bottom_limit;
    }
    else
    {
        println("Error: bottom limit data large then up data!");
    }
}
