#ifndef SIMRUN_H
#define SIMRUN_H

#include "include.h"
#include "model.h"
#include <qthread.h>



class simrun : public QThread,model
{
    //Q_OBJECT
public:
    simrun();
    //vatrua ~simrun;
    bool initSimulink(FLOAT32 a,
                      FLOAT32 u,
                      FLOAT32 v,
                      FLOAT32 delta_time,
                      string  file_name );

    void resetSimulink(string file_name, FLOAT32 v);
    bool runSimulink();
    POINTLIST getPointList();


Q_OBJECT

signals:
    void sendCurveData(CLDATA input_data);
    void sendTimeData(FLOAT32 time);
    void sendStatusData(STATUS staus);
    void sendShow(bool);

public slots:
    void getPatamData(FLOAT32 a,
                      FLOAT32 u,
                      FLOAT32 v,
                      FLOAT32 delta_time,
                      string  file_name  );
public:
    void run();
    FLOAT32     run_time;
    STATUS      status;
    POINTLIST   node_list;
    FLOAT32     delta_time;
    bool run_flag = false;

private:
    string      r_l_file_path;
    string      speed_path;
    SPEED2D     speed;
    FLOAT32     set_speed_value;

    FLOAT32 a;
    FLOAT32 u;
    CLDATA input_data;
};

#endif // SIMRUN_H
