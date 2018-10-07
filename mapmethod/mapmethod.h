/*
 * mapmethod.h
 *
 *  Created on: 2018年7月27日
 *      Author: admin
 */

#ifndef MAPMETHOD_MAPMETHOD_H_
#define MAPMETHOD_MAPMETHOD_H_
#include "basealgo/point2dprocess.h"
#include "basealgo/point2d.h"
#include "basealgo/typedef.h"
#include "basealgo/fileio.h"


namespace std {



class mapmethod {
public:
	mapmethod();
    mapmethod(POINT2D_LIST point2d_data_list);
    mapmethod(string file_name);

    void         setCurveDataList(POINT2D_LIST point_2d_data_list);
    void         setCurveDataListFromFile(string file_name);
    POINT2D_LIST getCurveDataList();


    void test();

    void show(POINT2D point_2d_data);

    mapmethod(const mapmethod &m);
    virtual ~mapmethod();
private:
    POINT2D processPosData( POINT2D point_2d_data,
                            POINT2D point_2d_data_bef);

private:
    POINT2D_LIST point_2d_list;
    POINT2D_LIST error_2d_list;
};

} /* namespace std */

#endif /* MAPMETHOD_MAPMETHOD_H_ */
