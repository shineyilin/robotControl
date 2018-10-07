/*
 * typedef.h
 *
 *  Created on: 2018��6��26��
 *      Author: admin
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_
#include <vector>
#include <iostream>


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define println(x) 	cout<<x<<endl
#define print(x)	cout<<x



#ifndef pi
#include <math.h>
#define pi 3.14159265358979323846
#endif


#define angle2radian(x) x*pi/180
#define radian2angle(x) x*180./pi



typedef struct
{
	int x;
	int y;
	int z;
}POINT3D;


typedef unsigned int       	uint32;
typedef unsigned long  int 	uint64;
typedef unsigned short int 	uint16;
typedef unsigned char      	uint8 ;

typedef int       			int32;
typedef long  int 			int64;
typedef short int 			int16;
typedef char      			int8 ;

typedef double	  			FLOAT;


typedef vector<vector <FLOAT> > MATRIX;
typedef vector<FLOAT>			VECTOR;


typedef struct
{
	FLOAT x;
	FLOAT y;
	char  flag;
}POINT2D;

typedef struct
{
	FLOAT x;
	FLOAT y;
	FLOAT z;
	char flag;
}POINT3;

typedef  vector<POINT2D> POINT2D_LIST;
typedef  vector<POINT3 > POINT3_LIST;




#define inf 1e64






#endif /* TYPEDEF_H_ */
