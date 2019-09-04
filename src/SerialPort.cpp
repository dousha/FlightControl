//
// Created by dousha on 2019/9/4.
//

#include <rom.h>
#include "SerialPort.h"

SerialPort::SerialPort() noexcept {}

void SerialPort::set(int port, int baud) noexcept {
	ROM_SysCtlPeripheralEnable(SERIAL_PORT_BASE[port]);
	ROM_SysCtlPeripheralEnable(SERIAL_PORT_NAME[port]);
	ROM_SysCtlPeripheralEnable(SERIAL_BASE_NAME[port]);
	while (!SysCtlPeripheralReady(SERIAL_BASE_NAME[port]));
	ROM_GPIOPinConfigure(SERIAL_RX_TX_PAIR[port * 2]);
	ROM_GPIOPinConfigure(SERIAL_RX_TX_PAIR[port * 2 + 1]);
	// TODO
}

void SerialPort::write(uint8_t c) noexcept {
	sendBuffer.put(c);
}

uint8_t SerialPort::read() noexcept {
	return recvBuffer.poll();
}
