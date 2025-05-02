#ifndef ARDUINO_UTILS_H
#define ARDUINO_UTILS_H

#include <QSerialPortInfo>
#include <QDebug>

inline bool isArduinoConnected() {
    qDebug() << "=== Serial ports detected ===";
    bool found = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port:" << info.portName();
        qDebug() << "Description:" << info.description();
        qDebug() << "Manufacturer:" << info.manufacturer();
        QString desc = info.description().toLower();
        QString manuf = info.manufacturer().toLower();
        if (desc.contains("arduino") ||
            manuf.contains("arduino") ||
            desc.contains("wch") ||
            manuf.contains("wch") ||
            desc.contains("ch340") ||
            manuf.contains("ch340") ||
            desc.contains("ftdi") ||
            manuf.contains("ftdi") ||
            desc.contains("silicon labs") ||
            manuf.contains("silicon labs") ||
            desc.contains("usb-serial") ||
            desc.contains("usb serial device") ||
            manuf.contains("usb-serial") ||
            manuf.contains("usb serial device")) {
            qDebug() << "✅ Arduino or compatible found on" << info.portName();
            found = true;
        }
    }
    if (!found) qDebug() << "❌ Arduino not found.";
    return found;
}

#endif // ARDUINO_UTILS_H
