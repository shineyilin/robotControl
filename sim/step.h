#ifndef STEP_H
#define STEP_H

#include <sim/typedefine.h>

namespace sim {

class step
{
public:
    //step    ();
    step    (double init_time = 1, double value = 1, double step_time = 0.001);
    void    setStepTime(double step_time = 0.001);
    double  getOutValue();
    double  getTime();
    void    show();
private:
    double init_time;
    double out_value;
    double set_value;
    double step_time;
    double total_time;

};
}//end of namespace sim
#endif // STEP_H
