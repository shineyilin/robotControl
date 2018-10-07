#include "my_deque.h"

my_deque::my_deque()
{
    this->total_size = 0;
    this->mydeque_current = NULL;
    this->mydeque_head    = NULL;
    this->mydeque_end     = NULL;
}

my_deque::my_deque(int data)
{
    MYDEQUE *new_deque_element = new MYDEQUE;
    new_deque_element->data.int_type = data;

    new_deque_element->before = NULL;
    new_deque_element->next   = NULL;

    this->mydeque_head = new_deque_element;
    this->mydeque_end  = new_deque_element;
    this->mydeque_current = new_deque_element;
    this->total_size ++;
}

my_deque::my_deque(double data)
{
    MYDEQUE *new_deque_element = new MYDEQUE;
    new_deque_element->data.double_type = data;

    new_deque_element->before = NULL;
    new_deque_element->next   = NULL;

    this->mydeque_head = new_deque_element;
    this->mydeque_end  = new_deque_element;
    this->mydeque_current = new_deque_element;
    this->total_size ++;
}


my_deque::my_deque(string data)
{
    MYDEQUE *new_deque_element = new MYDEQUE;

    uint32 length = sizeof( *(data.c_str()) );
    new_deque_element->data.string_type = new char( length );
    for (uint32 index = 0; index < length; index++)
    {
        *(new_deque_element->data.string_type+index) =\
                *(data.c_str()+index);
    }

    new_deque_element->before = NULL;
    new_deque_element->next   = NULL;

    this->mydeque_head = new_deque_element;
    this->mydeque_end  = new_deque_element;
    this->mydeque_current = new_deque_element;
    this->total_size ++;
}

bool my_deque::insert(int index, int insert_data)
{
    MYDEQUE *new_deque_element = new MYDEQUE;
    new_deque_element->data.int_type = insert_data;

    new_deque_element->before = NULL;
    new_deque_element->next   = NULL;

    MYDEQUE *serch_point = NULL;

    for (uint32 i = 0; i < this->total_size; i++)
    {

    }
    this->total_size ++;
}

