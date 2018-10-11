#ifndef SERIAL_CONNECT_H
#define SERIAL_CONNECT_H

#include <QtSerialPort/QtSerialPort>    // 访问串口
#include <QtSerialPort/QSerialPortInfo> // 提供系统中存在的串口信息
#include <QThread>
#include "basealgo/typedef.h"
#include <map>


class serial_connect : public QThread
{
public:
    serial_connect (QString serial_name = "COM1", qint32 baud_rate = 9600);
    bool    openSerialConnect  (   );
    void    scanSerialPort     (   );
    bool    isOpen             (   );
    //string  getSerialData      (   );

private slots:
    void getSerialData();

private:
    QString     serial_name;
    qint32      baud_rate;
//Q_OBJECT
    QSerialPort *serial_port = NULL;
    bool        serial_open_flag;
    uint32      serial_count;
    map<uint32, QString> com_name_map;

    QByteArray  serial_rev_data;

//    Q_OBJECT
};

#endif // SERIAL_CONNECT_H
