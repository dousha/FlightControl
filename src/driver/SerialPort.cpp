//
// Created by dousha on 2019/9/4.
//

#include <rom.h>
#include "SerialPort.h"

SerialPort::SerialPort() noexcept {}

void SerialPort::set(int port, int baud) noexcept {
	SysCtlPeripheralEnable(SERIAL_PORT_BASE[port]);
	SysCtlPeripheralEnable(SERIAL_PORT_NAME[port]);
	SysCtlPeripheralEnable(SERIAL_BASE_NAME[port]);
	while (!SysCtlPeripheralReady(SERIAL_BASE_NAME[port]));
	GPIOPinConfigure(SERIAL_RX_TX_PAIR[port * 2]);
	GPIOPinConfigure(SERIAL_RX_TX_PAIR[port * 2 + 1]);
	// TODO: some pins require unlocking
	GPIOPinTypeUART(SERIAL_PIN_NAME[port * 3], SERIAL_PIN_NAME[port * 3 + 1] | SERIAL_PIN_NAME[port * 3 + 2]);
}

void SerialPort::write(uint8_t c) noexcept {
	sendBuffer.put(c);
}

uint8_t SerialPort::read() noexcept {
	return recvBuffer.poll();
}
