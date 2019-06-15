Instalar QT 5.12


Instalar QSerialPort:
    1 - git clone git://code.qt.io/qt/qtserialport.git
    2 - cd qtserialport && qmake qtserialport.pro
    3 - sudo make install
 
Configurar porta serial pelo terminal:
    $ ls -l /dev/<nome da porta>
    $ sudo usermod -a -G dialout <nome do usuario>

    <nome da porta> é ttyACM* para Tiva e ttyUSB* para arduino
