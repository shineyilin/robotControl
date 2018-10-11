#include "connect/server.h"

server::server()
{
    if ( !this->createServer() )
    {
        Log("Create server error!");
    }
    else
    {
        println("connect signal... ");
        connect(server_define,SIGNAL(newConnection()), this,SLOT(newConnectClient()));
        //this->sendSocketData("ddd");
    }
}

bool server::createServer(QString ip_address, quint16 port)
{
    if (server_define)
    {
        server_define->close();
        server_define = NULL;
    }
    if (socket_define)
    {
        server_define->close();
        socket_define = NULL;
    }

    print("On create server ....  ");
    print("Create ");
    server_define = new QTcpServer();
    QHostAddress ip(ip_address);
    print ( ip.toString().toStdString());
    print(" ");
    print(port);
    print(" ");

    if (server_define->listen(ip,port))
    {
        println("sucess!!!");
        return true;
    }
    else
    {
        println("Error!!!");
        return false;
    }
    return false;
}

bool server::sendSocketData(QString send_data)
{
    if ( socket_define->write(send_data.toLatin1()) == -1)
    {
        println("send error!!");
        return false;
    }
    return true;
}

void server::run()
{
}

server::~server()
{
    if (server_define != NULL)
    {
        server_define->close();
        server_define->deleteLater();
    }
    if (socket_define != NULL)
        socket_define->close();
}

bool server::initializeServer(QString ip_address, quint16 port)
{
    if ( !this->createServer() )
    {
        Log("Create server error!");
        return false;
    }
    else
    {
        println("connect signal... ");
        connect(server_define,SIGNAL(newConnection()), this,SLOT(newConnectClient()));
        return true;
        //this->sendSocketData("ddd");
    }
    return false;
}

bool server::newConnectClient()
{
    socket_define = server_define->nextPendingConnection();
    print(socket_define->IPv4Protocol);
    println("new connection!!");
    connect(socket_define,SIGNAL(disconnected()), this, SLOT(disSocketConnect()));
    connect(socket_define,SIGNAL(readyRead()) , this, SLOT(readSocketData()));
    return true;
}

void server::readSocketData()
{
    QByteArray buffer;
    buffer = socket_define->readAll();
    print(buffer.toStdString());
}

void server::disSocketConnect()
{
    println("connect interrupt!!!");
}
