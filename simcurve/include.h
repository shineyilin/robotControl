#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qstring.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <stack>
//#include <graphics.h>


#include <QObject>
#include <QTimer>
#include <QTime>
#include <math.h>

using namespace std;

#define __debug__

#define eps 1e-4
#define R(a,u) (a*a + u*u)/(2*u)

typedef unsigned char		uint_8;
typedef unsigned short int	uint_16;
typedef unsigned int		uint_32;
typedef unsigned long  int	uint_64;
typedef char				int_8;
typedef short int			int_16;
typedef int					int_32;
typedef long  int			int_64;
typedef double              FLOAT32;

using namespace std;


typedef struct
{
	FLOAT32 x;
	FLOAT32 y;
}VECTOR2D;

typedef struct
{
	FLOAT32	value;
	FLOAT32	theta;
} SPEED2D;

typedef vector<FLOAT32>	 LIST1D;

typedef struct
{
    LIST1D  R;
    LIST1D  L;
    uint_32 length;
} CLDATA;


typedef struct
{
    FLOAT32 a;
    FLOAT32 u;
} CONPARAM;


typedef struct
{
    SPEED2D     extruction_speed;
    FLOAT32     current_length;
    VECTOR2D    control_speed;
    FLOAT32     a;
    FLOAT32     u;
    FLOAT32     current_time;
}STATUS;

typedef vector<double> FLOAT1D;
typedef vector<string> STR1D;

typedef vector<VECTOR2D> POINTLIST;

#endif // INCLUDE_H_INCLUDED
