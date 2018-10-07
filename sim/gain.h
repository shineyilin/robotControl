#ifndef GAIN_H
#define GAIN_H

#include <sim/typedefine.h>

namespace sim {

class gain
{
public:
    gain(double gain_value = 1);
    void    setGainValue(double gain_value);
    void    inputValue(double input_value);
    double  getOutValue();
    void    show();

private:
    double gain_value;
    double out_value;

};
}
#endif // GAIN_H
