// arduino.cpp

#include "arduino.h"
#include <QDebug>

// Constructor: initializes members
arduino::arduino()
    : serial(new QSerialPort()),
    arduinoPortName(""),
    arduinoIsAvailable(false),
    data()
{
}

// Attempts to find and open the Arduino Uno port.
// Returns  0 on success,
//         -1 if no matching port was found,
//          1 if port found but failed to open.
int arduino::connect_arduino(QSerialPort::BaudRate customBaud)
{
    // Scan all available serial ports
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : serialPortInfos) {
        // Check for matching vendor and product IDs
        if (info.hasVendorIdentifier() && info.vendorIdentifier() == arduinoVendorId &&
            info.hasProductIdentifier() && info.productIdentifier() == arduinoProducyId) {

            arduinoPortName = info.portName();
            serial->setPort(info);
            arduinoIsAvailable = true;
            break;
        }
    }

    // No Arduino found
    if (!arduinoIsAvailable)
        return -1;

    // Try to open the port in read/write mode
    if (serial->open(QIODevice::ReadWrite)) {
        // Configure serial parameters
        serial->setBaudRate(customBaud);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << "port opened";

        connect(serial, &QSerialPort::readyRead, this, [=]() {
            buffer.append(serial->readAll());

            // Look for full lines
            while (true) {
                int index = buffer.indexOf('\n');
                if (index == -1)
                    break;  // no full line yet

                QByteArray line = buffer.left(index);    // get line
                buffer.remove(0, index + 1);              // remove line + \n

                emit dataReceived(line);  // emit the full line!
            }
        });




        return 0;
    }

    // Port found but failed to open
    return 1;
}

// Closes the serial connection.
// Returns 0 on success (or if already closed), 1 on error.
int arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}

// Writes raw bytes to the Arduino.
void arduino::write_to_arduino(QByteArray bytes)
{
    if (serial->isWritable())
        serial->write(bytes);
}

// Reads all available bytes from the Arduino.
QByteArray arduino::read_from_arduino()
{
    if (serial->isReadable())
        data = serial->readAll();
    return data;
}

// Returns the underlying QSerialPort object.
QSerialPort *arduino::getSerial()
{
    return serial;
}

// Returns the port name of the connected Arduino.
QString arduino::getArduinoPortName()
{
    return arduinoPortName;
}
