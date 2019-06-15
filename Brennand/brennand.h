#ifndef BRENNAND_H
#define BRENNAND_H

#include <QSerialPortInfo>
#include <QElapsedTimer>
#include <QMainWindow>
#include <QSerialPort>
#include <iostream>
#include <QThread>
#include <thread>
#include "serialconnection.h"
#include "ui_brennand.h"
#include "robot.h"
#include "ser.h"

#define BR_SERIAL 38400
#define INVERTIDO 128
#define TAXA_TRANSMISSAO 40 //Milisegundos

using namespace std;

namespace Ui {
    class Brennand;
}

class Brennand : public QMainWindow{
    Q_OBJECT

public:
    uint8_t protocol[5];

    explicit Brennand(QWidget *parent = nullptr);
    unsigned char velMotor(bool isChecked, int valorSlider);
    [[ noreturn ]] void CriaRobo(ser*, int check);
    [[ noreturn ]] void InitProcura(ser*);
    bool comecouTransmissao();
    ~Brennand();
    [[ noreturn ]] void changePorts(QStringList);

private slots:
    void on_kickButton_clicked();
    void on_kickButton_2_clicked();
    void on_kickButton_3_clicked();
    void on_kickButton_4_clicked();

    void on_checkBox_2_clicked();
    void on_checkBox_12_clicked();
    void on_checkBox_6_clicked();
    void on_checkBox_10_clicked();
    void on_checkBox_13_clicked();
    void on_checkBox_14_clicked();
    void on_checkBox_15_clicked();
    void on_checkBox_16_clicked();

    void on_slider_motor1_valueChanged(int value);
    void on_slider_motor2_valueChanged(int value);
    void on_slider_motor3_valueChanged(int value);
    void on_slider_motor1_2_valueChanged(int value);
    void on_slider_motor2_2_valueChanged(int value);
    void on_slider_motor1_3_valueChanged(int value);
    void on_slider_motor3_3_valueChanged(int value);
    void on_slider_motor2_3_valueChanged(int value);
    void on_slider_motor3_4_valueChanged(int value);
    void on_slider_motor1_4_valueChanged(int value);
    void on_slider_motor2_4_valueChanged(int value);
    void on_slider_motor3_2_valueChanged(int value);

    void on_vel_Motor1_textChanged(const QString &arg1);
    void on_vel_Motor2_textChanged(const QString &arg1);
    void on_vel_Motor3_textChanged(const QString &arg1);
    void on_vel_Motor1_2_textChanged(const QString &arg1);
    void on_vel_Motor2_2_textChanged(const QString &arg1);
    void on_vel_Motor3_2_textChanged(const QString &arg1);
    void on_vel_Motor1_3_textChanged(const QString &arg1);
    void on_vel_Motor2_3_textChanged(const QString &arg1);
    void on_vel_Motor3_3_textChanged(const QString &arg1);
    void on_vel_Motor1_4_textChanged(const QString &arg1);
    void on_vel_Motor2_4_textChanged(const QString &arg1);
    void on_vel_Motor3_4_textChanged(const QString &arg1);

    void on_iniciar_Button_clicked();
    void on_parar_Button_clicked();
    void on_connectButton_clicked();
    void on_disconnectButton_clicked();

    void on_checkBox_17_clicked();
    void on_checkBox_18_clicked();
    void on_checkBox_19_clicked();
    void on_checkBox_22_clicked();
    void on_checkBox_21_clicked();
    void on_checkBox_20_clicked();
    void on_checkBox_27_clicked();
    void on_checkBox_28_clicked();
    void on_checkBox_26_clicked();
    void on_checkBox_31_clicked();
    void on_checkBox_30_clicked();
    void on_checkBox_29_clicked();

public slots:
    void enviaComando(int i);
    void procurarPortas();

private:
    QElapsedTimer timer[12];
    bool chutes[4];
    bool dribles[4];
    bool checkboxes[4];
    Ui::Brennand *ui;
    QSerialPort *devSerial;
    serialConnection *procSerial;
    bool controlePorta, controleTransmissao, iniciouTransmissao;
    int cont = 0;
};

#endif // BRENNAND_H
