#include "stmpclient.h"

SmtpClient::SmtpClient(QObject *parent) : QObject(parent)
{
}

bool SmtpClient::sendMail(const QString &from,
                          const QString &to,
                          const QString &subject,
                          const QString &body,
                          const QString &smtpServer,
                          int port,
                          const QString &username,
                          const QString &password)
{
    socket.connectToHostEncrypted(smtpServer, port);
    if (!socket.waitForEncrypted(5000)) return false;

    stream = new QTextStream(&socket);

    if (!waitForResponse("220")) return false;
    sendCommand("EHLO localhost");
    if (!waitForResponse("250")) return false;

    sendCommand("AUTH LOGIN");
    if (!waitForResponse("334")) return false;

    sendCommand(username.toUtf8().toBase64());
    if (!waitForResponse("334")) return false;

    sendCommand(password.toUtf8().toBase64());
    if (!waitForResponse("235")) return false;

    sendCommand("MAIL FROM:<" + from + ">");
    if (!waitForResponse("250")) return false;

    sendCommand("RCPT TO:<" + to + ">");
    if (!waitForResponse("250")) return false;

    sendCommand("DATA");
    if (!waitForResponse("354")) return false;

    *stream << "Subject: " << subject << "\r\n";
    *stream << "To: " << to << "\r\n";
    *stream << "From: " << from << "\r\n";
    *stream << "MIME-Version: 1.0\r\n";
    *stream << "Content-Type: text/html; charset=UTF-8\r\n";
    *stream << "\r\n" << body << "\r\n.\r\n";
    stream->flush();

    if (!waitForResponse("250")) return false;

    sendCommand("QUIT");
    socket.disconnectFromHost();
    return true;
}

void SmtpClient::sendCommand(const QString &command)
{
    *stream << command << "\r\n";
    stream->flush();
}

bool SmtpClient::waitForResponse(const QString &expectedCode)
{
    if (!socket.waitForReadyRead(5000)) return false;
    QString response = socket.readAll();
    return response.startsWith(expectedCode);
}
