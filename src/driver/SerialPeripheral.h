//
// Created by dousha on 2019/9/4.
//

#ifndef FLIGHTCONTROL_SERIALPERIPHERAL_H
#define FLIGHTCONTROL_SERIALPERIPHERAL_H


#include "SerialPort.h"

class SerialPeripheral : public SerialPort {
public:
	SerialPeripheral(int port, int baud);

	SerialPeripheral &operator<<(uint8_t c);

	SerialPeripheral &operator>>(uint8_t& c);

	virtual void parse();

	bool is_ready();
};

class GroundTransmitter : public SerialPeripheral {
public:
	GroundTransmitter();
};

#endif //FLIGHTCONTROL_SERIALPERIPHERAL_H
