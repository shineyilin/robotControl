#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


#ifndef sign
#define sign(x)  ( x>0? 1:(x<0?-1:0) )
#endif

#ifndef Abs
#define Abs(x) ( x>=0? x:-x )
#endif

#ifndef print
#define print(x) cout<<x
#endif

#ifndef println
#define println(x) cout<<x<<endl;
#endif

#endif // TYPEDEFINE_H
