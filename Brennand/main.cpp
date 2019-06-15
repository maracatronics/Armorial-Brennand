/*
    Brennand, interface de experimentação do Maracatronics

    Autores:    Gabriel Souza Marques
                Rafael Carneiro Reis de Souza
                Leonardo
                Pedro Jorge
                Victor

    Data:       08/06/2019
*/

#include <QSignalMapper>
#include <QApplication>
#include <iostream>
#include <QObject>
#include <QThread>
#include "brennand.h"
#include "crc.h"
#include "ser.h"

using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Brennand *brennand = new Brennand();
    ser serial_signal;

    brennand->show();

    QObject::connect(&serial_signal, SIGNAL(transmitindo(int)), brennand, SLOT(enviaComando(int)));
    QObject::connect(&serial_signal, SIGNAL(procurando()), brennand, SLOT(procurarPortas()));

    QThread *robo1 = QThread::create(&Brennand::CriaRobo, ref(*brennand), &serial_signal, 1);
    robo1->start();

    QThread *robo2 = QThread::create(&Brennand::CriaRobo, ref(*brennand), &serial_signal, 2);
    robo2->start();

    QThread *robo3 = QThread::create(&Brennand::CriaRobo, ref(*brennand), &serial_signal, 3);
    robo3->start();

    QThread *robo4 = QThread::create(&Brennand::CriaRobo, ref(*brennand), &serial_signal, 4);
    robo4->start();

    QThread *usb_search = QThread::create(&Brennand::InitProcura, ref(*brennand), &serial_signal);
    usb_search->start();

    app.exec();

    return 0;
}
