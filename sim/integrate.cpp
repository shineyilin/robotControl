#include "integrate.h"
namespace sim {
//integrate::integrate()
//{
//    this->init_value = 0;
//    this->bef_value  = this->init_value;
//    this->out_value  = this->init_value;
//    this->total_time = 0;
//}


integrate::integrate(integrateStruct &integrate_struct)
{
    this->init_value            = integrate_struct.init_value;
    this->input_value           = integrate_struct.input_value;
    this->out_value             = integrate_struct.out_value;
    this->bef_value             = integrate_struct.bef_value;
    this->step_time             = integrate_struct.step_time;
    this->total_time            = integrate_struct.total_time;
    this->reset_input_value     = integrate_struct.reset_input_value;
    this->reset_type            = integrate_struct.reset_type;
    this->reset_input_type      = integrate_struct.reset_input_type;
    this->reset_bef_input_value = integrate_struct.reset_bef_input_value;
    this->reset_flag            = integrate_struct.reset_flag;
}

void integrate::stepRun(integrateStruct &integrate_struct)
{
    this->inputValue(integrate_struct.input_value);
}

integrate::integrate(double init_value, double step_time)
{
    this->init_value = init_value;
    this->bef_value  = this->init_value;
    this->out_value  = this->init_value;
    this->step_time  = step_time;
    this->total_time = 0;
}

void integrate::setInitValue(double init_value)
{
    this->init_value = init_value;
}

void integrate::setStepTime(double step_time)
{
    this->step_time = step_time;
}

double integrate::getOutValue()
{
    return this->out_value;
}

double integrate::getTime()
{
    print("[time]:");
    println(this->total_time);
    return this->total_time;
}

void integrate::inputValue(double input_value)
{
    this->bef_value   = this->out_value;
    this->out_value  += input_value * this->step_time;
    this->total_time += this->step_time;
}

void integrate::show()
{
    print("[integrate]:");
    println(this->out_value);
}

void integrate::reset(int reset_input_value)
{
    if ( reset_input_value > this->reset_bef_input_value )
    {
        this->reset_type = 1;
    }
    else if (reset_input_value < this->reset_bef_input_value)
    {
        this->reset_type = -1;
    }
    else
    {
        this->reset_type = 0;
    }
    if (this->reset_type == this->reset_input_type)
    {
        this->reset_flag = true;
        this->reset();
    }
}

void integrate::reset()
{
    this->out_value  = this->init_value;
    this->reset_flag = false;
}

}//end of namespace sim
