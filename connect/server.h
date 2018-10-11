#ifndef SERVER_H
#define SERVER_H


#include "basealgo\typedef.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <string.h>
#include <QTextStream>

class server : public QObject
{
    Q_OBJECT
public:
    server();
    virtual ~server();
public:
    bool initializeServer( QString ip_address="10.65.149.120", quint16 port=1000);
    bool sendSocketData  ( QString send_data);
    void run();
private slots:
    void readSocketData  ();
    void disSocketConnect();
    bool newConnectClient();

private:
    bool createServer  ( QString ip_address="10.65.149.120", quint16 port=1000);
private:
    QTcpServer *server_define = NULL;
    QTcpSocket *socket_define = NULL;
};

#endif // SERVER_H
