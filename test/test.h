/*
 * test.h
 *
 *  Created on: 2018Äê7ÔÂ23ÈÕ
 *      Author: admin
 */

#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include "basealgo/typedef.h"
#include "test/test_matrix_solver.h"
#include "test/test_fit_method.h"
#include "test/test_point2d.h"
#include "test/test_mapmethod.h"
//#include "test_fit_method.h"
void testAll();




#include "basealgo/point2dprocess.h"
void testPoint2DProcess				();
#include "sim32process.h"
void testSim						();
#include "basealgo/matrix.h"
void testMatrixGaussMethod			();

#include "mapmethod/mapmethod.h"
void testMapMethod                  ();

#include "connect/server.h"
void testServerConnect              ();


#endif /* TEST_TEST_H_ */
