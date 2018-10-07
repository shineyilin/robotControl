//#include <QCoreApplication>

#include <sim/sim.h>

using namespace sim;

/******************************************************/

void initLoop()
{

}
void mainLoop(  double step_time  = 0.1,
                double begin_time = 0,
                double end_time   = 10    )
{
    int ntotal = (end_time - begin_time)/step_time;

/******************************************************/
    step      step_1(0);
    sum       sum_1 (0);
    integrate int_1 (0);
    integrate int_2 (0);
    gain      gain_1(1);
/******************************************************/
    step_1.setStepTime(step_time);

    int_1.setStepTime(step_time);
    int_1.setInitValue(0);

    int_2.setStepTime(step_time);
    int_2.setInitValue(0);

    double step_1_value = 0;
    double sum_1_value  = 0;
    double int_1_value  = 0;
    double int_2_value  = 0;
    double gain_1_value = 0;

/******************************************************/
    for (int index = 0; index <= ntotal; index ++)
    {
        step_1_value = step_1.getOutValue();
        //step_1.show();
        sum_1.addValue  (step_1_value);
        sum_1.minusValue(int_2_value);
        sum_1_value = sum_1.getOutValue();
        //sum_1.show();

        gain_1.inputValue(sum_1_value);
        gain_1_value = gain_1.getOutValue();


        int_1.inputValue(gain_1_value);
        int_1_value = int_1.getOutValue();
        //int_1.show();

        gain_1.inputValue(int_1_value);
        gain_1_value = gain_1.getOutValue();
        //gain_1.show();

        int_2.inputValue(int_1_value);
        int_2_value = int_2.getOutValue();
        int_2.show();
    }
}


void test_diff()
{
    step step_1(1);
    diff diff_1(0);
    integrate int_1(0);

    step_1.setStepTime(0.01);
    int_1.setStepTime(0.01);

    double step_1_value;
    double int_1_value;
    double diff_1_value;

    for (int index = 0; index < 10; index++)
    {
        step_1_value = step_1.getOutValue();
        step_1.show();

        int_1.inputValue(step_1_value);
        int_1_value = int_1.getOutValue();
        //int_1.show();

        diff_1.inputValue(int_1_value);
        diff_1_value = diff_1.getOutValue();
        diff_1.show();
        println(diff_1_value);
    }

    switch_sturation u;
    for (double i = -10; i < 10; i+=0.1)
    {
        u.inputValue(i);
        u.show();
    }
}

/******************************************************/


int test_sim_main(void)
{
    //mainLoop();
    test_diff();

    return 0;
}



/************************************
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("hello world\n");
    return a.exec();
}
************************************/
