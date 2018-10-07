#ifndef DEADZONE_H
#define DEADZO
#include<sim/typedefine.h>

class deadzone
{
public:
    deadzone(double up_limit = 1, double bottom_limit = -1);
    void    setUpLimit(double up_limit);
    void    setBottomLimit (double bottom_limit);
    void    inputValue     (double input_value);
    double  getOutValue    (   );
    void    show           (   );

protected:
    double input_value;
    double out_value;
    double up_limit;
    double bottom_limit;
};

#endif // DEADZONE_H
