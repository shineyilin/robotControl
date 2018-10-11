#include <QCoreApplication>

//============================================================================
// Name        : main.cpp
// Author      : YLG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "basealgo/matrix.h"
#include "basealgo/typedef.h"
#include "basealgo/point2dprocess.h"
#include "sim32process.h"
#include "basealgo/arraytype.h"
#include "basealgo/matrixsolver.h"
#include "test/test.h"
#include "sim/sim.h"
#include "mapmethod/mapmethod.h"
#include "connect/server.h"

using namespace std;
using namespace sim;

#include<stack>
#include<deque>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//  testSim();
//	testMatrixSolver();
//	testPoint2DProcess();
//	testGaussMethod();
//	testAll();
//	outPrint(3);
//	outPrint("fg");
//  integrate int_1;
//  testMapMethod();

    testServerConnect();

    cout << "!!!end program!!!" << endl; // prints !!!Hello World!!!

    //return a.exec();
    //return 0;
}





