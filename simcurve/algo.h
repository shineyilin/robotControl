#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include "include.h"


class algo
{
public:
    algo(){}
    /////////////////////////////////////////////////////////////////////
    void        extrudeModelCurve       ( POINTLIST	&node_list,
                                          SPEED2D	speed,
                                          FLOAT32   delta_time );

    SPEED2D     extrudeModelSpeed       ( FLOAT32	a,
                                          FLOAT32	u,
                                          FLOAT32   v,
                                          FLOAT32	delta_time );
    FLOAT32     linearInseert           ( LIST1D R, LIST1D L, FLOAT32 x);
    void        writePointList          ( char *file_name, POINTLIST node_list);

    /////////////////////////////////////////////////////////////////////
protected:
    void        addPointToPointList     ( POINTLIST &node_list, VECTOR2D node);
    void        printPoint              ( VECTOR2D node);
    void        printPointList          ( POINTLIST node_list);
    VECTOR2D    rotatePoint             ( VECTOR2D &node, FLOAT32 tran_mat[2][2]);
    VECTOR2D    rotatePoint             ( VECTOR2D &node, FLOAT32 theta);
    VECTOR2D    movePoint               ( VECTOR2D &node, VECTOR2D move);

    POINTLIST   getTranslatePointList   ( POINTLIST	&node_list,
                                          FLOAT32	theta   	);

    POINTLIST   getTranslatePointList   ( POINTLIST	&node_list,
                                          VECTOR2D	add_node,
                                          FLOAT32	theta      );

    POINTLIST   addExtrudePointList     ( POINTLIST	&node_list,
                                          VECTOR2D	add_node,
                                          FLOAT32	theta      );

private:

    void unitTest5();
    void unitTest1();
    void unitTest2();
    void unitTest3();
    void unitTest4();

};
#endif // ALGO_H_INCLUDED
