#include "serial_connect.h"

serial_connect::serial_connect(QString serial_name, qint32 baud_rate)
{

    this->serial_open_flag = false;
    serial_port = new QSerialPort();
    serial_port->setPortName(serial_name          );
    serial_port->setBaudRate(baud_rate            );
    serial_port->setDataBits(QSerialPort::Data8   );
    serial_port->setParity  (QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop );

}

bool serial_connect::openSerialConnect()
{
    if ( serial_port->open(QSerialPort::ReadWrite) )
    {
        this->serial_open_flag = true;
        connect(serial_port,SIGNAL(readyRead()),this,SLOT(getSerialData()));
        return true;
    }
    else
        return false;
}

void serial_connect::scanSerialPort()
{
    QSerialPort *new_serial_port = new QSerialPort();
    uint32 com_name_map_index    = 0;
    if (new_serial_port != NULL)
    {
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            QSerialPort serial;
            serial.setPort(info);
            if (serial.open(QIODevice::ReadWrite))
            {
                this->com_name_map[com_name_map_index] = \
                        serial.portName();
                com_name_map_index ++;
            }
            else
            {
                println("can not open the serial port!!!");
            }
            serial.close();
        }
    }
    println("error");
}

bool serial_connect::isOpen()
{
    if ( this->serial_port->isOpen() )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void serial_connect::getSerialData()
{
    QByteArray serial_data = this->serial_port->readAll();
    this->serial_rev_data += serial_data;
}


