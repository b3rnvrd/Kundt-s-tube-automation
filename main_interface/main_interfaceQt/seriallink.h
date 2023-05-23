#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <QObject>
#include <QSerialPort>

class seriallink : public QObject
{
    Q_OBJECT
public:
    explicit seriallink(QObject *parent = nullptr);
    ~seriallink();

    void openConnection();
    void closeConnection();
    void write(const QByteArray &messageToWrite);
    bool isOpen();
    bool isWritable();
    QByteArray read();
    void setPort(QString port);
    void clear(QSerialPort::Directions directions = QSerialPort::AllDirections);
private slots:
    void newData();

signals:
    void gotNewData(QByteArray data);

private:
    QSerialPort _serial;

public slots:

protected slots:

};

#endif // SERIALLINK_H
