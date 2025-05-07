#include "arduino.h"
#include "qdebug.h"

Arduino::Arduino() {
    serial = new QSerialPort();
    arduino_is_available = false;
    arduino_port_name = "";
}

int Arduino::connect_arduino()
{
    // Recherche du port sur lequel est connectée la carte Arduino
    foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts()) {
        qDebug() << "Found port:";
        qDebug() << "Name:" << port.portName();

        if (port.hasVendorIdentifier())
            qDebug() << "Vendor ID:" << QString("0x%1").arg(port.vendorIdentifier(), 4, 16, QChar('0'));
        if (port.hasProductIdentifier())
            qDebug() << "Product ID:" << QString("0x%1").arg(port.productIdentifier(), 4, 16, QChar('0'));

        // Comparaison avec les IDs connus de l’Arduino
        if (port.hasVendorIdentifier() && port.hasProductIdentifier()) {
            if (port.vendorIdentifier() == arduino_uno_vendor_id &&
                port.productIdentifier() == arduino_uno_producy_id) {

                arduino_is_available = true;
                arduino_port_name = port.portName();
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;

    // Configuration et ouverture du port série si l'Arduino est disponible
    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
    }

    return 1; // Erreur si non trouvé ou non ouvert
}


int Arduino::close_arduino() {
    if (serial->isOpen()) {
        serial->close();
        return 0; // Fermeture réussie
    }
    return -1; // Échec de fermeture
}

void Arduino::write_to_arduino(QByteArray data) {
    if (serial->isWritable()) {
        serial->write(data);
    }else{
        qDebug()<<"couldn't write to serial ";}
}

QByteArray Arduino::read_from_arduino()
{
    QByteArray data;

    if (serial->isOpen() && serial->isReadable()) {
        data = serial->readAll();
        return data;
    }

    return QByteArray(); // <== Ajout important pour éviter le warning
}


QSerialPort* Arduino::getserial() {
    return serial;
}

QString Arduino::getarduino_port_name() {
    return arduino_port_name;
}
