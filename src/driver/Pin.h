//
// Created by 李家豪 on 2019/9/19.
//

#ifndef FLIGHTCONTROL_PIN_H
#define FLIGHTCONTROL_PIN_H

#include "HardwareSpec.h"

enum PinType {
	GPIO,
	UART,
	I2C,
	SPI,
	CAN,
};

class Pin {
public:
	Pin(address_t hwRegAddr);
	void configure(PinType type);
};


#endif //FLIGHTCONTROL_PIN_H
