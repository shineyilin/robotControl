#ifndef SERVER_H
#define SERVER_H


#include "basealgo\typedef.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <string.h>
#include <QTextStream>
#include <QNetworkInterface>


#ifndef Local_ip_address
#define Local_ip_address "10.65.149.120"
#endif
#ifndef Local_port
#define Local_port 1000
#endif

enum robot_ID
{
    robot_ID_1,
    robot_ID_2
};

typedef struct robot_connect
{
    robot_ID    id;
    bool        connect_flag;
    QTcpSocket  *socket_define;
}robot_connect;

class server : public QObject
{

    Q_OBJECT
public:
    server();
    server(QString ip_address, quint16 port);

    virtual ~server();
public:
    bool initializeServer( QString ip_address, quint16 port);
    bool initializeServer();
    bool sendSocketData  (QTcpSocket *socket_define, QString send_data);
    void run();
    bool closeServer();

private slots:
    QByteArray  readSocketData  ();
    void        disSocketConnect();
    bool        newConnectClient();

signals:
    void writeSocketDvvvataSignal(int, QString    x);

private:
    bool    createServer    ( QString ip_address, quint16 port);
    bool    createServer    ();
    bool    clearSocketList ();
    QString getLocalAddress ();
    void    clearVoidSocker ();

private:
    QTcpServer          *server_define = NULL;
    vector<QTcpSocket *> socket_list;
    const qint8         max_connect_number = 4;
};

#endif // SERVER_H
