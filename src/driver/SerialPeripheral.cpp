//
// Created by dousha on 2019/9/4.
//

#include "SerialPeripheral.h"

SerialPeripheral::SerialPeripheral(int port, int baud) : SerialPort() {
	this->set(port, baud);
}

SerialPeripheral &SerialPeripheral::operator<<(uint8_t c) {
	this->write(c);
	return *this;
}

SerialPeripheral &SerialPeripheral::operator>>(uint8_t& c) {
	c = this->read();
	return *this;
}

GroundTransmitter::GroundTransmitter() : SerialPeripheral(1, 115200) { }
