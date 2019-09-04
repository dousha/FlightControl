//
// Created by dousha on 2019/9/4.
//

#ifndef FLIGHTCONTROL_SERIALPERIPHERAL_H
#define FLIGHTCONTROL_SERIALPERIPHERAL_H


#include "SerialPort.h"

class SerialPeripheral : SerialPort {
public:
	SerialPeripheral(int port, int baud);

	virtual SerialPeripheral &operator<<(uint8_t c) = 0;

	virtual SerialPeripheral &operator>>(uint8_t c) = 0;
};


#endif //FLIGHTCONTROL_SERIALPERIPHERAL_H
