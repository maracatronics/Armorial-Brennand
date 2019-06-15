#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

class serialConnection{
public:
    serialConnection(QSerialPort *myDev);
    ~serialConnection();

    QStringList loadPorts();

    bool connect(QString Port, u_int32_t bd);
    bool disconnect(void);

    qint64 write(const char *cmd);
    QString read();
    QString read(int TamanhoBuffer);

protected:
   QSerialPort *devSerial;
};

#endif
