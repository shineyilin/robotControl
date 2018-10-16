#include "connect/server.h"

server::server()
{
    initializeServer();
}

server::server(QString ip_address, quint16 port)
{
    initializeServer(ip_address, port);
}

/*********************************************************************
 *
 *  void create a server with input ip address and port
 * *******************************************************************/


bool server::createServer(QString ip_address, quint16 port)
{
    if (server_define)
    {
        server_define->close();
        server_define = NULL;
    }
    this->clearSocketList();

#ifdef __debug_socket_connect__
    print("On create server ....  ");
    print("Create ");
    server_define = new QTcpServer();
    QHostAddress ip(ip_address);
    print ( ip.toString().toStdString());
    print(" ");
    print(port);
    print(" ");
#endif

    if (server_define->listen(ip,port))
    {
#ifdef __debug_socket_connect__
        println("sucess!!!");
#endif
        return true;
    }
    else
    {
#ifdef __debug_socket_connect__
        println("Error!!!");
#endif
        return false;
    }
    return false;
}

/*********************************************************************
 *
 *  void create a server with default param
 * *******************************************************************/

bool server::createServer()
{
    if ( createServer(  getLocalAddress(), 8080) )
    {
        return true;
    }
    return false;
}


/*********************************************************************
 *
 *  clear socket list
 * *******************************************************************/
bool server::clearSocketList()
{
    foreach( QTcpSocket *socket_define, this->socket_list  )
    {
        if (socket_define)
        {
            socket_define->close();
            socket_define = NULL;
        }
        else
        {
            return false;
        }
    }
    this->socket_list.clear();
   return true;
}

/*********************************************************************
 *
 *  get network address
 * *******************************************************************/

QString server::getLocalAddress()
{
    QString ipv4_address;
    foreach (QHostAddress t, QNetworkInterface::allAddresses() )
    {
        if ( t.protocol() == QAbstractSocket::IPv4Protocol && \
             t != QHostAddress::LocalHost   )
        {
            ipv4_address = t.toString();
        }
    }
    return ipv4_address;
}

void server::clearVoidSocker()
{
    for (uint index = 0; index < this->socket_list.size(); index++)
    {
        if ( this->socket_list.at(index)->peerPort() == 0)
        {
            this->socket_list.at(index)->close();
            this->socket_list.at(index)->deleteLater();
            this->socket_list.erase(this->socket_list.begin()+index);
        }
    }
}

/*********************************************************************
 *
 * *******************************************************************/

bool server::sendSocketData(QTcpSocket *socket_define,QString send_data)
{
    if ( socket_define->write(send_data.toLatin1()) == -1)
    {
#ifdef __debug_socket_connect__
        println("send error!!");
#endif
        return false;
    }
    return true;
}

void server::run()
{
}

bool server::closeServer()
{
    this->clearSocketList();

    if (this->server_define)
    {
        this->server_define->close();
        this->server_define = NULL;
    }
    else
    {
        return false;
    }
    return true;
}

server::~server()
{
    if (server_define != NULL)
    {
        server_define->close();
        server_define->deleteLater();
    }
    this->clearSocketList();
}


bool server::initializeServer(QString ip_address, quint16 port)
{


    if ( !this->createServer(ip_address, port) )
    {
#ifdef __debug_socket_connect__
        Log("Create server error!");
#endif
        return false;
    }

    else
    {
#ifdef __debug_socket_connect__
        println("connect signal... ");
#endif
        connect(server_define,SIGNAL(newConnection()), this,SLOT(newConnectClient()));
        return true;
        //this->sendSocketData("ddd");
    }
    return false;
}

bool server::initializeServer()
{
    if ( !this->createServer() )
    {
#ifdef __debug_socket_connect__
        Log("Create server error!");
#endif
        return false;
    }

    else
    {
#ifdef __debug_socket_connect__
        println("connect signal... ");
#endif
        connect(server_define,SIGNAL(newConnection()), this,SLOT(newConnectClient()));
        return true;
        //this->sendSocketData("ddd");
    }
    return false;
}

bool server::newConnectClient()
{
    QTcpSocket *new_socket_define = NULL;
    new_socket_define = server_define->nextPendingConnection();

#ifdef __debug_socket_connect__
    println("new connection!!");
#endif
    connect(new_socket_define,SIGNAL(disconnected()), this, SLOT(disSocketConnect()));
    connect(new_socket_define,SIGNAL(readyRead()) , this, SLOT(readSocketData()));
    this->socket_list.push_back( new_socket_define );
    return true;
}

QByteArray server::readSocketData()
{
    QByteArray buffer;

    foreach (QTcpSocket *socket_define, this->socket_list)
    {
        buffer = socket_define->readAll();
        if (buffer.isEmpty())
        {
            continue;
        }
        else
        {

#ifdef __debug_socket_connect__
            print(buffer.toStdString());
            break;
#endif
        }
    }
    return buffer;
}

void server::disSocketConnect()
{
    this->clearVoidSocker();
#ifdef __debug_socket_connect__
    println("connect interrupt!!!");
#endif
}

