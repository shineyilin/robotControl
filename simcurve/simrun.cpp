#include "simrun.h"



simrun::simrun()
{

}

void simrun::getPatamData(  FLOAT32 a,
                            FLOAT32 u,
                            FLOAT32 v,
                            FLOAT32 delta_time,
                            string  file_name )
{
    this->run_time = 0;
    this->status.a = a;
    this->status.u = u;
    this->status.control_speed.x    = 0;
    this->status.control_speed.y    = 0;
    this->status.current_length     = 0;
    this->status.current_time       = 0;
    this->status.extruction_speed.value = v;
    this->status.extruction_speed.theta = 0;

    this->run_time =0;
    this->r_l_file_path = file_name;
    this->delta_time = delta_time;

    this->speed.theta = 0;
    this->speed.value = v;
    run_flag = false;

}


bool simrun::initSimulink(  FLOAT32 a,
                            FLOAT32 u,
                            FLOAT32 v,
                            FLOAT32 delta_time,
                            string  file_name )
{
    this->run_time = 0;
    this->status.a = a;
    this->status.u = u;
    this->status.control_speed.x = 0;
    this->status.control_speed.y = 0;
    this->status.current_length = 0;
    this->status.current_time = 0;
    this->status.extruction_speed.value = v;
    this->status.extruction_speed.theta = 0;

    this->run_time =0;
    this->r_l_file_path = file_name;
    this->delta_time = delta_time;

    this->speed.theta = 0;
    this->speed.value = v;
    this->set_speed_value = v;
    this->input_data.L.clear();
    this->input_data.R.clear();
    this->input_data.length = 0;

    this->node_list.clear();
    run_flag = false;

    char *temp_file_name = (char *)malloc(sizeof(char)*r_l_file_path.size());
    temp_file_name       = (char *)r_l_file_path.data();

    readDataFromFile(temp_file_name, input_data);
    //printf("%d", input_data.length);
    if (input_data.length == 0)
        return false;
    else
    {
        return true;
    }
    //printClData(input_data);
}

void simrun::resetSimulink( string file_name, FLOAT32 v)
{
    this->run_time = 0;
    this->run_time = 0;
    this->status.a = a;
    this->status.u = u;
    this->status.control_speed.x    = 0;
    this->status.control_speed.y    = 0;
    this->status.current_length     = 0;
    this->status.current_time       = 0;
    this->status.extruction_speed.value = v;
    this->status.extruction_speed.theta = 0;

    this->run_time =0;
    this->r_l_file_path = file_name;
    this->delta_time = delta_time;

    this->speed.theta = 0;
    this->speed.value = v;
    run_flag = false;
}

bool simrun::runSimulink()
{
    //srand(time(NULL));
    //FLOAT32 data;

    //readDataFromFile( file_name,input_data);
    //printf("%s\n", file_name);
    //printClData(input_data);
    //return ;
   // while( true )
    {
        //printf("time=%.3f ", run_time);
        //printStatus(current);
        //printClData(input_data);
        if (getControlParam(input_data, status, delta_time) == false )
            return false;
        status.extruction_speed.value = set_speed_value+rand()%100/20+cos(run_time*100);
        speed = extrudeModelSpeed(status.a, status.u,status.extruction_speed.value,delta_time);
        //printf("speed=%f, %f \n", speed.value, speed.theta);
        extrudeModelCurve(node_list, speed, delta_time);
        run_time += delta_time;
        //getchar()
        return true;
    }
}

POINTLIST simrun::getPointList()
{
    return node_list;
}

void simrun::run()
{
    uint step           = 0;
    uint save_per_step  = 100;
    this->run_flag = true;
    while (true)
    {
        if ( this->runSimulink() == false)
        {
            break;
        }
        step++;
        if (step == save_per_step )
        {
            step = 0;
            emit sendShow(true);
        }
    }
}
