#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QSslSocket>
#include <QTextStream>
#include <QDebug>

class SmtpClient : public QObject
{
    Q_OBJECT

public:
    explicit SmtpClient(QObject *parent = nullptr);
    bool sendMail(const QString &from,
                  const QString &to,
                  const QString &subject,
                  const QString &body,
                  const QString &smtpServer,
                  int port,
                  const QString &username,
                  const QString &password);

private:
    QSslSocket socket;
    QTextStream *stream;
    bool waitForResponse(const QString &expectedCode);
    void sendCommand(const QString &command);
};

#endif // SMTPCLIENT_H
