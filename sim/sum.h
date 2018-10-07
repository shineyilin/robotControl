#ifndef SUM_H
#define SUM_H

#include<sim/typedefine.h>

namespace sim {
class sum
{
public:
    sum(double init_value);
    void    setInitValue(double init_value);
    void    addValue   (double value);
    void    minusValue (double value);
    double  getOutValue();
    void    reset      ();
    void    show       ();
private:
    double out_value;
    double init_value;
};
}
#endif // SUM_H
