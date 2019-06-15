#include "serialconnection.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QThread>

using namespace std;

string GetStdoutFromCommand(string cmd);

serialConnection::serialConnection(QSerialPort *myDev){
    this->devSerial=myDev;
}

serialConnection::~serialConnection(){}


QStringList serialConnection::loadPorts(){
    QStringList devs;

    //O CÓDIGO ABAIXO SERVE PARA CONFIGURAR AS PORTAS PARA AMBIENTES LINUX
    //*************************************************************************************************
    /*string comand_str = "usermod -a -G dialout ";
    FILE *name;
    char user[255], *comand_char = NULL;
    int c1;

    system("ls -l /dev/ttyACM*");
    system("ls -l /dev/ttyUSB*");

    name = popen("whoami", "r");
    fgets(user, sizeof(user), name);
    pclose(name);
    comand_char = (char *)realloc(comand_char, (comand_str.length() + strlen(user))*sizeof(char));
    for(c1=0; c1<comand_str.length(); c1++){
        comand_char[c1] = comand_str[c1];
    }
    for(int c2=0; c2<strlen(user); c1++, c2++){
        comand_char[c1] = user[c2];
    }
    comand_char[c1] = '\0';
    system(comand_char);*/
    //*************************************************************************************************

    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
        this->devSerial->setPort(info);

        if (this->devSerial->open(QIODevice::ReadWrite)) {
            this->devSerial->close();
            devs << info.portName();
        }

    }

    return devs;
}

/**
 * @brief serialConnection::connect
 *
 * Função que recebe os parametros Porta, BaudRate e FlowControl e realiza conexão
 *
 * @param QString Port(Porta Serial), uint32_t bd(BaudRate), uint8_t fc(FlowControl)
 * @return
 */

bool serialConnection::connect(QString Port, u_int32_t bd){
    //Device Serial Port
    devSerial->setPortName(Port);
    qDebug() << "Dispositivo Porta Serial: " << Port;

    //BaudRate
    switch (bd) {
    case 2400:
        qDebug() << "Baudrate: 2400";
        devSerial->setBaudRate(QSerialPort::Baud2400);
        break;
    case 4800:
        qDebug() << "Baudrate: 4800";
        devSerial->setBaudRate(QSerialPort::Baud4800);
        break;
    case 9600:
        qDebug() << "Baudrate: 9600";
        devSerial->setBaudRate(QSerialPort::Baud9600);
        break;
    case 19200:
        qDebug() << "Baudrate: 19200";
        devSerial->setBaudRate(QSerialPort::Baud19200);
        break;
    case 38400:
        qDebug() << "Baudrate: 38400";
        devSerial->setBaudRate(QSerialPort::Baud38400);
        break;
    case 115200:
        qDebug() << "Baudrate: 115200";
        devSerial->setBaudRate(QSerialPort::Baud115200);
        break;
    }

    //FlowControl
    devSerial->setFlowControl(QSerialPort::NoFlowControl);

    //Configurações adicionais
    devSerial->setDataBits(QSerialPort::Data8);
    devSerial->setParity(QSerialPort::NoParity);
    devSerial->setStopBits(QSerialPort::OneStop);

    if(devSerial->open(QIODevice::ReadWrite)){
        qDebug() << "Porta serial aberta com sucesso!";
        return true;
    }
    else{
        qDebug() << "Falha ao abrir porta serial!";
        qDebug() << "Erro: " << devSerial->error();
        return false;
    }
}

/**
 * @brief serialConnection::disconnect
 *
 * Função Desconectar, realiza a limpeza do componente e fecha
 *
 * @param
 * @return
 */
bool serialConnection::disconnect(){
    devSerial->clear();
    devSerial->close();

    if(devSerial->error() == 0 && !devSerial->isOpen()){
        qDebug() << "Porta serial fechada com sucesso!";
        return true;
    }
    else{
        qDebug() << "Falha ao fechar a porta serial! ERRO: " << devSerial->error();
        return false;
    }
}

/**
 * @brief serialConnection::write
 *
 * Função para escrever na serial, recebe um ponteiro de caracteres já no formato do const char* do write
 *
 * @param const char *cmd
 * @return void
 */
qint64 serialConnection::write(const char *cmd){
    qint64 writeLength;

    writeLength = devSerial->write(cmd,qstrlen(cmd));
    return writeLength;
}

/**
 * @brief serialConnection::Read
 *
 * Função Realiza a leitura do que chegar pela serial apos escrever na mesma, e devolve um QString
 *
 * @param
 * @return QString
 */
QString serialConnection::read(){
     QString bufRxSerial;

     /* Awaits read all the data before continuing */
     while (devSerial->waitForReadyRead(20)) {
         bufRxSerial += devSerial->readAll();
     }
     return bufRxSerial;
}

/**
 * @brief serialConnection::read
 * Overloaded
 *
 * Função Realiza a leitura do que chegar pela serial apos escrever na mesma, e devolve uma QString
 * neste caso é enviado um inteiro com o numero de caracteres do buffer de recepção
 *
 * @param int
 * @return QString
 */
QString serialConnection::read(int TamanhoBuffer){
    char buf[TamanhoBuffer];

    if (devSerial->canReadLine()) {
        devSerial->read(buf, qint64(sizeof(buf)));
    }

    return buf;

}
