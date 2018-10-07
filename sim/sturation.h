#ifndef STURATION_H
#define STURATION_H


#include<sim/typedefine.h>

class sturation
{
public:
    sturation(double up_border = 1, double bottom_border=-1);
    void    inputValue      (double input_value);
    void    setUpBorder     (double up_border);
    void    setBottomBorder (double bottom_border);

    double  getOutValue();
    void    show();
private:
    double up_border;
    double bottom_border;
    double out_value;
};

#endif // STURATION_H
