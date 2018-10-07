#ifndef MY_DEQUE_H
#define MY_DEQUE_H


#include "typedef.h"
#include <qstring.h>


union MYTYPE
{
    int     int_type;
    double  double_type;
    char*   string_type;
};

typedef struct MYDEQUE
{
    MYTYPE data;
    struct MYDEQUE *before;
    struct MYDEQUE *next;

}MYDEQUE;




class my_deque
{
public:
    my_deque();
    my_deque(int    data);
    my_deque(double data);
    my_deque(string data);

//    my_deque(const my_deque& m);

    /**********************************************
     * insert method
     * *******************************************/
    bool insert(int index, int    insert_data);
    bool insert(int index, double insert_data);
    bool insert(int index, string insert_data);

    /**********************************************
     * push back method
     * *******************************************/
    void push_back ( int     push_data);
    void push_back ( double  push_data);
    void push_back ( string  push_data);

    /**********************************************
     * push front method
     * *******************************************/
    void push_front( int     push_data);
    void push_front( double  push_data);
    void push_front( string  push_data);

    /**********************************************
     * pop front method
     * *******************************************/
    auto pop_front();
    /**********************************************
     * pop back method
     * *******************************************/
    auto pop_back();
    auto at(int32 index);
    auto operator[] (const uint32 index);

    uint32 size();



private:
    MYDEQUE *mydeque_head    = NULL;
    MYDEQUE *mydeque_end     = NULL;
    MYDEQUE *mydeque_current = NULL;
    uint32  total_size;
};

#endif // MY_DEQUE_H
