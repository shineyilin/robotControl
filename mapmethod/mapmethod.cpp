/*
 * mapmethod.cpp
 *
 *  Created on: 2018Äê7ÔÂ27ÈÕ
 *      Author: admin
 */

#include <mapmethod/mapmethod.h>

namespace std {

mapmethod::mapmethod() {
	// TODO Auto-generated constructor stub

}

mapmethod::mapmethod(POINT2D_LIST point2d_data_list)
{
    this->point_2d_list = point2d_data_list;
}

mapmethod::mapmethod(string file_name)
{
    fileio file_hand(file_name);
    this->point_2d_list = file_hand.readSplitDataToPoint2DList();
    file_hand.close();
}

void mapmethod::test()
{
    POINT2D point_1;
    POINT2D point_bef;

    FLOAT theta = 0;

    POINT2D_LIST point_2d_input_list;

    for (FLOAT angle = 0; angle <= 90; angle+=10 )
    {

        theta = angle * pi/180;
        point_1.x =angle;
        point_1.y =1* sin(theta);

        point_2d_input_list.push_back(point_1);
    }
    this->setCurveDataList(point_2d_input_list);
    this->getCurveDataList();
}


void mapmethod::setCurveDataList(POINT2D_LIST point_2d_data_list)
{
    this->point_2d_list = point_2d_data_list;
}

void mapmethod::setCurveDataListFromFile(string file_name)
{
    fileio file_hand(file_name);
    this->point_2d_list = file_hand.readSplitDataToPoint2DList();
    file_hand.close();
}

POINT2D_LIST mapmethod::getCurveDataList()
{
    POINT2D_LIST point_2d_out_list;
    uint32 length = this->point_2d_list.size();

    POINT2D point_2d_data;
    POINT2D point_2d_data_bef;

    POINT2D point_2d_out_data;
    for (uint32 index = length - 1; index > 0; index --)
    {
        point_2d_data      =  this->point_2d_list[index];
        point_2d_data_bef  =  this->point_2d_list[index-1];
        point_2d_out_data  =  this->processPosData(point_2d_data,
                                                   point_2d_data_bef);
        point_2d_out_list.push_back(point_2d_out_data);
        this->show(point_2d_data);
        this->show(point_2d_out_data);
    }
    return point_2d_out_list;
}


void mapmethod::show(POINT2D point_2d_data)
{
    print("x: ");
    print(point_2d_data.x);
    print(" y: ");
    println(point_2d_data.y);
}

mapmethod::~mapmethod() {
    // TODO Auto-generated destructor stub
}


/*********************************************************************
 *  x       y
 *  length  r
 * *******************************************************************/
POINT2D mapmethod::processPosData(POINT2D point_2d_data,
                                  POINT2D point_2d_data_bef )
{
    POINT2D out_lr_data;
    FLOAT   delta_curve_length;
    FLOAT   delta_curve_theta;
    FLOAT   delta_x;
    FLOAT   delta_y;

    delta_x = point_2d_data.x-point_2d_data_bef.x;
    delta_y = point_2d_data.y-point_2d_data_bef.y;
    delta_curve_length = sqrt( pow(delta_x,2) + pow( delta_y,2 ) );

    delta_curve_theta  = atan( delta_y/delta_x );

//    print(" delta_x: ");
//    print(delta_x);
//    print(" delta_y: ");
//    println(delta_y);
//    print(" delta_curve_length: ");
//    print(delta_curve_length);
//    print(" delta_curve_theta: ");
//    println(delta_curve_theta*180/pi);

   out_lr_data.x = delta_curve_length;
   out_lr_data.y = delta_curve_theta;
   return out_lr_data;

}

} /* namespace std */
