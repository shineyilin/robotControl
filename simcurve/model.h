#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "include.h"
#include "algo.h"



class model : public algo
{
public:
    model() {}
    virtual ~model() {}
    FLOAT32     getCurrentRadius( CLDATA input_data, FLOAT32 x);
    STR1D       splitText       ( string val, char flag);
    FLOAT1D     strListToFloat  ( STR1D str_list);
    FLOAT1D     strToFloat1D    ( string val, char flag);
    void        printStrList    ( STR1D str_list);
    void        printClData     ( CLDATA input_data );
    void        printFlostList  ( FLOAT1D float_list);
    string      readLine        ( FILE *hand);
    CLDATA      readDataFromFile( char *file_name, CLDATA &input_data);
    CONPARAM    getParamEx( FLOAT32 a, FLOAT32 u ,FLOAT32 radius);
    CONPARAM    getParam( FLOAT32 a, FLOAT32 u ,FLOAT32 radius);

    bool        getControlParam(    CLDATA      cldata,
                                    STATUS      &current,
                                    FLOAT32     delta_time);
    void        getRandSpeed( FLOAT32 current_time );
    void        printStatus(STATUS current );
    void        loopSimulink();
    void        unitTest6();
    void        unitTest7();
};

#endif // MODEL_H_INCLUDED
