#include "step.h"

namespace sim {
//step::step()
//{
//    this->init_time  = 1;
//    this->set_value  = 1;
//    this->out_value  = this->set_value;
//    this->total_time = 0;
//}

step::step(double init_time, double value, double step_time)
{
    this->init_time     = init_time;
    this->set_value     = value;
    this->step_time     = step_time;
    this->out_value     = 0;
    this->total_time    = 0;
}

void step::setStepTime(double step_time)
{
    this->step_time = step_time;
}

double step::getOutValue()
{
   if (this->total_time >= this->init_time)
   {
        this->total_time += this->step_time;
        this->out_value = this->set_value;
        return this->out_value;
   }
   this->total_time += this->step_time;
   return 0;
}

double step::getTime()
{
    print("[time]:");
    println(this->total_time);
}

void step::show()
{
    print("[step]:");
    println(this->out_value);
}

}//end of namespace sim
