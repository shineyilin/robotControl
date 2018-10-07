#ifndef INTEGRATE_H
#define INTEGRATE_H

/********************************************************
 *
 *                   DEMO
 * This is a demo show how to use the integrate class
 *  integrate int_1     ( init_value );
 *  int_1.setStepTime   ( step_time  );
 *  int_1.setInitValue  ( init_value );
 *
 * *****************************************************/

#include<sim/typedefine.h>

namespace sim {


typedef struct integrateStruct
{
    double init_value;
    double input_value;
    double out_value;
    double bef_value;
    double step_time;
    double total_time;
    int    reset_input_value;
    int    reset_type;
    int    reset_input_type;
    int    reset_bef_input_value;
    bool   reset_flag;

}integrateStruct;


class integrate
{
private:
    integrate       (integrateStruct &integrate_struct);
    void            stepRun(integrateStruct &integrate_struct);
    integrateStruct getInfo();

public:
//  integrate();
    integrate(double init_value = 0, double step_time = 0.01);
    void   setInitValue(double init_value);
    void   setStepTime (double step_time = 0.01);
    double getOutValue ();
    double getTime     ();
    virtual void   inputValue  (double input_value);
    void   show();
    void   reset(int reset_input_value);

private:
    void reset();

protected:
    double init_value;
    double input_value;
    double out_value;
    double bef_value;
    double step_time;
    double total_time;

    int     reset_input_value;
    int     reset_type;
    int     reset_input_type;
    int     reset_bef_input_value;
    bool    reset_flag;
};

}
#endif // INTEGRATE_H
