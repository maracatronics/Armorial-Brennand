#include "robot.h"
#include <iomanip>  // Includes std::hex
#include "crc.h"
#include "iostream"

using namespace std;

Robot::Robot(int id){
    this->id=id;
}

Robot::~Robot(){}

void Robot::mountPackage(unsigned char flags, unsigned char v1, unsigned char v2, unsigned char v3){
    this->comands[0]='M';
    this->comands[1]= static_cast<unsigned char>(this->id+flags);
    this->comands[2]= v1;
    this->comands[3]= v2;
    this->comands[4]= v3;

    this->calcCRC(this->comands, sizeof (this->comands), this->protocol);
}

void Robot::calcCRC(unsigned char *comands, size_t tam, char *protocol){
    std::copy(comands, comands + SIZE_COMANDS, protocol);
    uint16_t crc = CRC::Calculate(comands, tam, CRC::CRC_16_XMODEM());

    protocol[SIZE_PROTOCOL-2] = static_cast<char>(crc >> 8);
    protocol[SIZE_PROTOCOL-1] = static_cast<char>(crc & 0xff);
}
