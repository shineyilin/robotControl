#include "include.h"
#include "algo.h"
#include <string>
#include "model.h"


/**********************************************************
* get current radius by current distance
* this function means to get radius
* input data is a two dimension data,
* when x input to the function this
* will find the line insert data in between
**********************************************************/

FLOAT32 model::getCurrentRadius(CLDATA input_data, FLOAT32 x)
{
    LIST1D    R;
    LIST1D    L;
    R = input_data.R;
    L = input_data.L;
    return linearInseert(R,L,x);
}
/**********************************************************
* function : split text
* split by flag
* return a string one dimension string data
***********************************************************/
STR1D model::splitText(string val, char flag)
{
    string  temp;
    uint_32 length;
    STR1D   val_list;
    length = val.size();
    //printf("string = %s\n", val.c_str());
    //printf("length = %d\n", length);

    for (uint_32 index =0; index < length; index++)
    {
        //printf("index = %d\n", index);
        if (val[index] == flag )
        {
            if (temp.size())
            {
                val_list.push_back(temp);
                //printf("val = %s\n", temp.c_str());
                temp.clear();
            }
            continue;
        }
        if (index == length -1 )
        {
            temp += val[index];
            if ( temp.size() )
            {
                val_list.push_back(temp);
                //printf("val = %s\n", temp.c_str());
                temp.clear();
            }
            continue;
        }
        temp += val[index];
    }
    return val_list;
}
/*********************************************************
* function : change the string list to float list
* input string list
* output float list
**********************************************************/

FLOAT1D model::strListToFloat(STR1D str_list)
{
    uint_32 length = str_list.size();
    FLOAT1D float_list;
    FLOAT32 temp;
    for (uint_32 index = 0; index < length; index++)
    {
        temp = atof(str_list[index].c_str());
        float_list.push_back( temp );
    }
    return float_list;
}
/**********************************************************
* function : change string to float list
* input val flag
* output float list
**********************************************************/
FLOAT1D model::strToFloat1D(string val, char flag)
{
    FLOAT1D     float_list;
    STR1D       str_list;
    str_list    = splitText(val, flag);
    float_list  = strListToFloat(str_list);
    return float_list;
}

/**********************************************************
* function : print string list
* input string
**********************************************************/
void model::printStrList(STR1D str_list)
{
    uint_32 length = str_list.size();
    printf("======string list data:======\n");
    printf("length = %d\n", length);
    for (uint_32 index = 0; index < length; index++)
    {
        printf("%s\n",str_list[index].c_str());
    }
    printf("\n");
}

void model::printClData( CLDATA input_data )
{
    uint_32 length = input_data.length;
    FLOAT32 L;
    FLOAT32 R;
    printf("============CL data============\n");
    printf("length=%d\n", length);
    for (uint_32 index = 0; index < length; index++)
    {
        R = input_data.R[index];
        L = input_data.L[index];
        printf("L = %f, R = %f\n", L,R);
        //getchar();
    }
}

/**********************************************************
* function : print float list
* input float list
**********************************************************/
void model::printFlostList(FLOAT1D float_list)
{
    uint_32 length = float_list.size();
    printf("======string list data:======\n");
    printf("length = %d\n", length);
    for (uint_32 index = 0; index < length; index++)
    {
        printf("%f\n",float_list[index]);
    }
    printf("\n");
}


/**********************************************************
* function : read a line file from file handle
* input file handle
**********************************************************/
string model::readLine(FILE *hand)
{
    string val;
    char ch;
    ch = fgetc(hand);
    if (ch == EOF) return "eof";
    while(ch != EOF )
    {
        if ( ch != '\n' )
        {
            val += ch;
            ch = fgetc(hand);
            continue;
        }
        return val;
    }
    return val;
}

/**********************************************************
* function : read a float list from file handle
* input file name
**********************************************************/
CLDATA model::readDataFromFile(char *file_name, CLDATA &input_data)
{
    FILE *hand = fopen(file_name, "r");
    string  val;
    FLOAT1D float1d;
    CLDATA  new_input_data;
    printf("on read data from file!!!\n");
    if (hand == NULL)
    {
        printf("can not open file !!!\n");
        input_data.length = 0;
        return new_input_data;
    }
    input_data.length = 0;
    while (true)
    {
        val = readLine(hand);
        if (val == "eof")       break;
        if (val.size() == 0)    continue;
        float1d = strToFloat1D(val,' ');
        input_data.L.push_back( float1d[0] );
        input_data.R.push_back( float1d[1] );
        input_data.length ++;
    }
    //printClData(input_data);
    fclose(hand);
    return input_data;
}



CONPARAM model::getParam( FLOAT32 a, FLOAT32 u ,FLOAT32 radius)
{
    FLOAT32 ka;
    FLOAT32 ku;
    FLOAT32 a1;
    FLOAT32 u1;
    CONPARAM param;
    uint    counter = 0;
    //printf("a=%.3f u=%.3f R = %.3f \n", a,u,R(a,u));
    if (u == 0)
    {
        if (radius > 0 ) u = 1e-8;
        else if(radius < 0) u = -1e-8;
    }
    if ( R(a,u) * radius <0 )
    {
        u = -u;
    }
    while(true)
    {
        ka = a/u;
        ku = 1-((a*a + u*u)/(2*u*u));
        a1 = a-(R(a,u)-radius)/ka;
        u1 = u-(R(a,u)-radius)/ku;

        //printf("a=%.3f u=%.3f R = %.3f \n", a1,u1,R(a1,u1));
        //getchar();
        if( fabs(a1-a) < eps and fabs(u1-u) < eps)
        {
            param.a = a1;
            param.u = u1;
            return param;
        }
        //a = a1;
        u = u1;
        counter ++;
        if (counter >256) break ;
    }
}

CONPARAM model::getParamEx( FLOAT32 a, FLOAT32 u ,FLOAT32 radius)
{
    FLOAT32 ka;
    FLOAT32 ku;
    FLOAT32 a1;
    FLOAT32 u1;
    FLOAT32 da;
    FLOAT32 du;
    FLOAT32 bef_radius;
    CONPARAM param;
    da = 0.1;
    du = 0.1;
    while(true)
    {
        ka = a/u;
        ku = 1-((a*a + u*u)/(2*u*u));
        a1 = a+ka*da;
        u1 = u+ku*du;
        bef_radius = R(a,u);
        if (bef_radius == radius )
        {
            param.a = a;
            param.u = u;
            return param;
        }
        else if ( bef_radius < radius )
        {
           // if (  )
        }
        else if (bef_radius > radius )
        {

        }
    }
}

bool model::getControlParam(    CLDATA      cldata,
                                STATUS      &current,
                                FLOAT32     delta_time    )
{
    FLOAT32     radius;
    FLOAT32     current_len;
    CONPARAM    con_param;
    FLOAT32 speed   = current.extruction_speed.value;
    current_len     = current.current_length;
    current_len    += delta_time * speed;
   // printf("%f %f", cldata.L [cldata.length-1], current_len );
    if (cldata.L [cldata.length-1] <= current_len) return false;
    radius          = getCurrentRadius(cldata, current_len);
    // printf("len=%.3f radius=%.3f\n", current_len, radius);
    con_param = getParam(current.a, current.u, radius);
    current.control_speed.y = (con_param.a-current.a) / delta_time;
    current.control_speed.x = (con_param.u-current.u) / delta_time;

    current.a = con_param.a;
    current.u = con_param.u;

    current.current_length = current_len;
    return true;
}




void model::getRandSpeed( FLOAT32 current_time )
{
    static float bef_time;

}


void model::printStatus(STATUS current )
{
    FLOAT32 a;
    FLOAT32 u;
    FLOAT32 length;
    FLOAT32 vu;
    FLOAT32 va;
    a = current.a;
    u = current.u;
    va = current.control_speed.y;
    vu = current.control_speed.x;

    length = current.current_length;
    //printf("##########################\n");
    printf("--len=%.3f a=%.3f u=%.3f va=%.3f vu = %.3f R= %.3f\n", \
                                                length, a,u,va,vu, R(a,u));
    //printf("--len=%.3f u=%.3f vu = %.3f\n", length, a,u,va,vu);

    //printf(" a=%.3f u=%.3f\n", length, a,u);

    //printf("##########################\n");
}

void model::loopSimulink()
{
    CLDATA input_data;
    srand(time(NULL));
    FLOAT32 data;
    readDataFromFile("data.txt", input_data);

    FLOAT32 run_time   = 0;
    FLOAT32 delta_time = 1e-3;
    STATUS current;

    current.a = 200;
    current.u = 0.001;
    current.control_speed.x = 0;
    current.control_speed.y = 0;
    current.current_length  = 0;
    current.current_time    = 0;
    current.extruction_speed.theta = 0;
    current.extruction_speed.value = 1;
    SPEED2D speed;
    POINTLIST node_list;
    while( true )
    {
        printf("time=%.3f ", run_time);
        //printStatus(current);
        //printClData(input_data);
        if (getControlParam(input_data, current, delta_time) == false )
            break;
        speed = extrudeModelSpeed(current.a, current.u,\
                                  current.extruction_speed.value,delta_time);
        printf("value=%f, %f \n", speed.value, speed.theta);
        extrudeModelCurve(node_list, speed, delta_time);
		run_time += delta_time;
        //getchar();
    }
    writePointList("point.txt", node_list);
}

void model::unitTest6()
{
    loopSimulink();
}


void model::unitTest7()
{
    srand(time(NULL));
    CLDATA input_data;
    for (int i = 0; i < 10; i++)
    printf("%d\n",rand());
    input_data = readDataFromFile("data.txt", input_data);

    //getControlParam( input_data,  );
    FLOAT32 data;
    getParam(150,20,408);

    loopSimulink();
    return ;
    for (float x = 0; x < 7; x +=0.1)
    {
        data = getCurrentRadius(input_data, x);
        printf("x = %f, val = %f\n", x, data);
    }

}
