#ifndef LIMIT_INTEGRATE_H
#define LIMIT_INTEGRATE_H

#include<sim/integrate.h>


class limit_integrate: public sim::integrate
{
public:
    limit_integrate(double up_limit = 1, double bottom_limit = -1);
    virtual void inputValue (double input_value);
    void    setUpLimit      (double up_limit);
    void    setBottomLimit  (double bottom_limit);

protected:
    double up_limit;
    double bottom_limit;
};

#endif // LIMIT_INTEGRATE_H
