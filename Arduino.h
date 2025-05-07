#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>

class arduino : public QObject
{
    Q_OBJECT
public:
    arduino();
    int connect_arduino(QSerialPort::BaudRate customBaud);
    int close_arduino();
    void write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort * getSerial();
    QString getArduinoPortName();

private:

    QSerialPort * serial;
    static const quint16 arduinoVendorId=9025;
    static const quint16 arduinoProducyId=67;
    QString arduinoPortName;
    bool arduinoIsAvailable;
    QByteArray data;
    QByteArray buffer;

signals:
    void dataReceived(QByteArray data);

};

#endif // ARDUINO_H
