#include "seriallink.h"
#include <QDebug>
#include <QMessageBox>

seriallink::seriallink(QObject *parent) : QObject(parent)
{
    _serial.setPortName("COM10");// COM10 Eliott COM5 Patrick
    _serial.setBaudRate(QSerialPort::Baud115200);
    _serial.setDataBits(QSerialPort::Data8);
    _serial.setParity(QSerialPort::NoParity);
    _serial.setStopBits(QSerialPort::OneStop);
    _serial.setFlowControl(QSerialPort::NoFlowControl);

    connect(&_serial, &QSerialPort::readyRead, this, &seriallink::newData);

}

seriallink::~seriallink(){
    closeConnection();
}

void seriallink::closeConnection(){
    _serial.close();
}

void seriallink::openConnection(){
    if(!_serial.open(QIODevice::ReadWrite))
    {
        qDebug() << "connexion avec la carte Arduino impossible";
    }
    else qDebug() << "connexion ok";
}

void seriallink::write(const QByteArray &messageToWrite){
    _serial.write(messageToWrite);
}

bool seriallink::isOpen(){
    return _serial.isOpen();
}

bool seriallink::isWritable(){
    return _serial.isWritable();
}

QByteArray seriallink::read()
{
    return _serial.readAll();
}

void seriallink::newData(){
    emit gotNewData(_serial.readAll());
}
