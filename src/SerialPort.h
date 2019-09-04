//
// Created by dousha on 2019/9/4.
//

#ifndef FLIGHTCONTROL_SERIALPORT_H
#define FLIGHTCONTROL_SERIALPORT_H

#include <sysctl.h>
#include <hw_memmap.h>
#include <cstdint>
#include <driverlib/pin_map.h>
#include "RingBuffer.h"

constexpr int SERIAL_BUFFER_SIZE = 64;
constexpr uint32_t SERIAL_PORT_BASE[] = {SYSCTL_PERIPH_GPIOA,
										 SYSCTL_PERIPH_GPIOB,
										 SYSCTL_PERIPH_GPIOD,
										 SYSCTL_PERIPH_GPIOC,
										 SYSCTL_PERIPH_GPIOC,
										 SYSCTL_PERIPH_GPIOE,
										 SYSCTL_PERIPH_GPIOD,
										 SYSCTL_PERIPH_GPIOE};
constexpr uint32_t SERIAL_PORT_NAME[] = {SYSCTL_PERIPH_UART0,
										 SYSCTL_PERIPH_UART1,
										 SYSCTL_PERIPH_UART2,
										 SYSCTL_PERIPH_UART3,
										 SYSCTL_PERIPH_UART4,
										 SYSCTL_PERIPH_UART5,
										 SYSCTL_PERIPH_UART6,
										 SYSCTL_PERIPH_UART7};
constexpr uint32_t SERIAL_BASE_NAME[] = {UART0_BASE,
										 UART1_BASE,
										 UART2_BASE,
										 UART3_BASE,
										 UART4_BASE,
										 UART5_BASE,
										 UART6_BASE,
										 UART7_BASE};
constexpr uint32_t SERIAL_RX_TX_PAIR[] = {GPIO_PA0_U0RX,
										  GPIO_PA1_U0TX,
										  GPIO_PB0_U1RX,
										  GPIO_PB1_U1TX,
										  GPIO_PD6_U2RX,
										  GPIO_PD7_U2TX,
										  GPIO_PC6_U3RX,
										  GPIO_PC7_U3TX,
										  GPIO_PC4_U4RX,
										  GPIO_PC5_U4TX,
										  GPIO_PE4_U5RX,
										  GPIO_PE5_U5TX,
										  GPIO_PD4_U6RX,
										  GPIO_PD5_U6TX,
										  GPIO_PE0_U7RX,
										  GPIO_PE1_U7TX};

class SerialPort {
public:
	SerialPort() noexcept;

	void set(int port, int baud) noexcept;

	void write(uint8_t c) noexcept;

	uint8_t read() noexcept;

protected:
	RingBuffer<uint8_t> recvBuffer = RingBuffer<uint8_t>(SERIAL_BUFFER_SIZE);
	RingBuffer<uint8_t> sendBuffer = RingBuffer<uint8_t>(SERIAL_BUFFER_SIZE);
};


#endif //FLIGHTCONTROL_SERIALPORT_H
