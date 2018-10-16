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
#include "connect/connect.h"

using namespace std;
using namespace sim;

#include<stack>
#include<deque>
#include<thread>

void run()
{
    QTextStream qin(stdin);
    QString cc;
    while(true)
    {
        print("start: ");
        getchar();
        print(cc.toStdString());
    }
}

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
    qint16 port = 1000;
    QString ip = "192.168.0.1";
    connect m();
//    server m(ip,port);

    cout << "!!!end program!!!" << endl; // prints !!!Hello World!!!
    return a.exec();

    //return 0;
}





