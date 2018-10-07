#include "diff.h"

namespace sim {

diff::diff(double init_value, double step_time)
{
    this->bef_value = init_value;
    this->step_time = step_time;
}

void diff::setInitValue(double init_value)
{
    this->bef_value = init_value;
}

void diff::setStepTime(double step_time)
{
    this->step_time = step_time;
}

void diff::inputValue(double value)
{
    this->out_value = (value - this->bef_value)/this->step_time;
    this->bef_value = value;
}

double diff::getOutValue()
{
    return this->out_value;
}

void diff::show()
{
    print("[diff]:");
    println(this->out_value);
}


}//end of namespace sim
