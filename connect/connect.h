#ifndef CONNECT_H
#define CONNECT_H

#include "connect/server.h"
#include "connect/serial_connect.h"



class connect:public server
{
public:
    connect();
    connect(QString ip_address, quint16 port):server(ip_address,port){}
private:

};

#endif // CONNECT_H
