#ifndef DIFF_H
#define DIFF_H

#include <sim/typedefine.h>

namespace sim {

class diff
{
public:
    diff(double init_value = 0, double step_time = 0.01);
    void    setInitValue   (double init_value);
    void    setStepTime    (double step_time = 0.01);
    void    inputValue     (double value);
    double  getOutValue    ();
    void    show           ();
private:
    double bef_value;
    double out_value;
    double step_time;
};

}
#endif // DIFF_H
