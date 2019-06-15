#include "brennand.h"
#include "ui_brennand.h"

Brennand::Brennand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Brennand)
{
    ui->setupUi(this);
    ui->vel_Motor1->setText("0");
    ui->vel_Motor2->setText("0");
    ui->vel_Motor3->setText("0");

    ui->vel_Motor1_2->setText("0");
    ui->vel_Motor2_2->setText("0");
    ui->vel_Motor3_2->setText("0");

    ui->vel_Motor1_3->setText("0");
    ui->vel_Motor2_3->setText("0");
    ui->vel_Motor3_3->setText("0");

    ui->vel_Motor1_4->setText("0");
    ui->vel_Motor2_4->setText("0");
    ui->vel_Motor3_4->setText("0");

    controlePorta=false;
    controleTransmissao=false;
    iniciouTransmissao = false;

    for(int i = 0; i < 12 ; i++){
       timer[i].start();
    }

    ui->boxDevice->addItem("No Port Connected");

    devSerial = new QSerialPort();
    procSerial = new serialConnection(devSerial);
}

Brennand::~Brennand(){
    delete ui;
}

void Brennand::on_slider_motor1_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor1->setText(valueString);
}

void Brennand::on_slider_motor2_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor2->setText(valueString);
}

void Brennand::on_slider_motor3_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor3->setText(valueString);
}

void Brennand::on_slider_motor1_2_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor1_2->setText(valueString);
}

void Brennand::on_slider_motor2_2_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor2_2->setText(valueString);
}

void Brennand::on_slider_motor3_2_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor3_2->setText(valueString);
}
void Brennand::on_slider_motor1_3_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor1_3->setText(valueString);
}

void Brennand::on_slider_motor2_3_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor2_3->setText(valueString);
}

void Brennand::on_slider_motor3_3_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor3_3->setText(valueString);
}

void Brennand::on_slider_motor1_4_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor1_4->setText(valueString);
}

void Brennand::on_slider_motor2_4_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor2_4->setText(valueString);
}

void Brennand::on_slider_motor3_4_valueChanged(int value){
    QString valueString = QString::number(value);
    ui->vel_Motor3_4->setText(valueString);
}

void Brennand::on_vel_Motor1_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor1->setValue(value);
}

void Brennand::on_vel_Motor2_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor2->setValue(value);
}

void Brennand::on_vel_Motor3_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor3->setValue(value);
}

void Brennand::on_vel_Motor1_2_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor1_2->setValue(value);
}

void Brennand::on_vel_Motor2_2_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor2_2->setValue(value);
}

void Brennand::on_vel_Motor3_2_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor3_2->setValue(value);
}

void Brennand::on_vel_Motor1_3_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor1_3->setValue(value);
}

void Brennand::on_vel_Motor2_3_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor2_3->setValue(value);
}

void Brennand::on_vel_Motor3_3_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor3_3->setValue(value);
}

void Brennand::on_vel_Motor1_4_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor1_4->setValue(value);
}

void Brennand::on_vel_Motor2_4_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor2_4->setValue(value);
}

void Brennand::on_vel_Motor3_4_textChanged(const QString &arg1){
    int value = arg1.toInt();
    if(value >= 0 && value <= 127)
        ui->slider_motor3_4->setValue(value);
}

void Brennand::on_kickButton_clicked(){
    chutes[0] = true;
}

void Brennand::on_kickButton_3_clicked(){
    chutes[1] = true;
}

void Brennand::on_kickButton_2_clicked(){
    chutes[2] = true;
}

void Brennand::on_kickButton_4_clicked(){
    chutes[3] = true;
}

void Brennand::on_checkBox_13_clicked(){
    checkboxes[0] = !checkboxes[0];
}

void Brennand::on_checkBox_14_clicked(){
    checkboxes[1] = !checkboxes[1];
}

void Brennand::on_checkBox_15_clicked(){
    checkboxes[2] = !checkboxes[2];
}

void Brennand::on_checkBox_16_clicked(){
    checkboxes[3] = !checkboxes[3];
}

void Brennand::on_checkBox_2_clicked(){
    dribles[0] = !dribles[0];
}

void Brennand::on_checkBox_12_clicked(){
    dribles[1] = !dribles[1];
}

void Brennand::on_checkBox_6_clicked(){
    dribles[2] = !dribles[2];
}

void Brennand::on_checkBox_10_clicked(){
    dribles[3] = !dribles[3];
}

void Brennand::on_checkBox_17_clicked(){
    timer[0].start();
}

void Brennand::on_checkBox_18_clicked(){
    timer[1].start();
}

void Brennand::on_checkBox_19_clicked(){
    timer[2].start();
}

void Brennand::on_checkBox_22_clicked(){
    timer[3].start();
}

void Brennand::on_checkBox_21_clicked(){
    timer[4].start();
}

void Brennand::on_checkBox_20_clicked(){
    timer[5].start();
}

void Brennand::on_checkBox_27_clicked(){
    timer[6].start();
}

void Brennand::on_checkBox_28_clicked(){
    timer[7].start();
}

void Brennand::on_checkBox_26_clicked(){
    timer[8].start();
}

void Brennand::on_checkBox_31_clicked(){
    timer[9].start();
}

void Brennand::on_checkBox_30_clicked(){
    timer[10].start();
}

void Brennand::on_checkBox_29_clicked(){
    timer[11].start();
}

void Brennand::on_connectButton_clicked(){
    procSerial->connect(ui->boxDevice->currentText(), BR_SERIAL);
    controlePorta=true;
}

void Brennand::on_disconnectButton_clicked(){
    procSerial->disconnect();
    controlePorta=false;
}

void Brennand::on_iniciar_Button_clicked(){
    controleTransmissao=true;
    if(controlePorta && controleTransmissao){
        qDebug() << "Trasmissão iniciada";
        iniciouTransmissao = true;
    }
    else if (!controlePorta && controleTransmissao){
        qDebug() << "É preciso abrir a porta";
    }
}

void Brennand::on_parar_Button_clicked(){
    controleTransmissao=false;
    if(controlePorta && !controleTransmissao){
        qDebug()<<"Trasmissão parada";
        iniciouTransmissao = false;
    }
}

unsigned char Brennand::velMotor(bool isChecked, int valorSlider){
    return isChecked? static_cast<unsigned char>(valorSlider | INVERTIDO) : static_cast<unsigned char>(valorSlider);
}

void Brennand::CriaRobo(ser *s, int check){
    QElapsedTimer timer_transmissao;
    bool startTime_transmissao = true;

    checkboxes[check-1] = false;

    while(true){
        if(iniciouTransmissao){
            if(startTime_transmissao){
                timer_transmissao.start();
                startTime_transmissao = false;
            }

            if(timer_transmissao.hasExpired(TAXA_TRANSMISSAO) && checkboxes[check-1]){

                emit s->transmitindo(check);

                startTime_transmissao = true;
            }
        }
    };
}

void Brennand::InitProcura (ser *s){
    QElapsedTimer timer_procura;
    bool startTime_procura = true;

    while(true){
        if(!controlePorta){
            if(startTime_procura){
                timer_procura.start();
                startTime_procura = false;
            }

            if(timer_procura.hasExpired(1000)){
                emit s->procurando();

                startTime_procura = true;
            }
        }
    }
}

void Brennand::procurarPortas(){
    QStringList listPorts = procSerial->loadPorts();
    ui->boxDevice->clear();
    if(listPorts.isEmpty()) ui->boxDevice->addItem("No Port Connected");
    else ui->boxDevice->addItems(listPorts);
}

void Brennand :: enviaComando(int id){
    cout<< "ID: " << id << endl;
    Robot robo(id);
    unsigned char val1=0,val2=0,val3=0,flag=0;

    if(chutes[id-1]){
        flag = 64;
        chutes[id-1] = false;
    }
    else if(dribles[id-1]){
        flag = 16;
    }

    if(id == 1){
        if(timer[0].elapsed() < 1000){
            val1 = 0;
        }
        else{
            val1 = velMotor(ui->checkBox_17->isChecked(),ui->slider_motor1->value());
        }

        if(timer[1].elapsed() < 1000){
            val2 = 0;
        }
        else{
            val2 = velMotor(ui->checkBox_18->isChecked(),ui->slider_motor2->value());
        }

        if(timer[2].elapsed() < 1000){
            val3 = 0;
        }
        else{
            val3 = velMotor(ui->checkBox_19->isChecked(),ui->slider_motor3->value());
        }

    }

    if(id==2){
        if(timer[3].elapsed() < 1000){
            val1 = 0;
        }
        else{
            val1 = velMotor(ui->checkBox_22->isChecked(),ui->slider_motor1_2->value());
        }

        if(timer[4].elapsed() < 1000){
            val2 = 0;
        }
        else{
            val2 = velMotor(ui->checkBox_21->isChecked(),ui->slider_motor2_2->value());
        }

        if(timer[5].elapsed() < 1000){
            val3 = 0;
        }
        else{
            val3 = velMotor(ui->checkBox_20->isChecked(),ui->slider_motor3_2->value());
        }

    }

    if(id==3){

        if(timer[6].elapsed() < 1000){
            val1 = 0;
        }
        else{
            val1 = velMotor(ui->checkBox_27->isChecked(),ui->slider_motor1_3->value());
        }

        if(timer[7].elapsed() < 1000){
            val2 = 0;
        }
        else{
            val2 = velMotor(ui->checkBox_28->isChecked(),ui->slider_motor2_3->value());
        }

        if(timer[8].elapsed() < 1000){
            val3 = 0;
        }
        else{
            val3 = velMotor(ui->checkBox_26->isChecked(),ui->slider_motor3_3->value());
        }

    }

    if(id==4){

        if(timer[9].elapsed() < 1000){
            val1 = 0;
        }
        else{
            val1 = velMotor(ui->checkBox_31->isChecked(),ui->slider_motor1_4->value());
        }

        if(timer[10].elapsed() < 1000){
            val2 = 0;
        }
        else{
            val2 = velMotor(ui->checkBox_30->isChecked(),ui->slider_motor2_4->value());
        }

        if(timer[11].elapsed() < 1000){
            val3 = 0;
        }
        else{
            val3 = velMotor(ui->checkBox_29->isChecked(),ui->slider_motor3_4->value());
        }

    }

    robo.mountPackage(flag, val1, val2, val3);

    if(flag == 64){
        for(int count = 0;count<=50;count++){
            devSerial->write(robo.protocol, sizeof(robo.protocol));
        }
    }else{
        devSerial->write(robo.protocol, sizeof(robo.protocol));
    }
}

bool Brennand::comecouTransmissao(){
    return this->iniciouTransmissao;
}


