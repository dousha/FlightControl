//
// Created by dousha on 2019/9/4.
//

#include <cstdint>
#include <driverlib/rom.h>
#include <driverlib/sysctl.h>
#include <inc/hw_memmap.h>
#include <driverlib/gpio.h>

#include "Main.h"

[[noreturn]] int main() {
	Main main = Main();
	main.loop();
}

Main::Main() noexcept {
	// do setups here
	ROM_FPULazyStackingEnable();
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
	// TODO configure serial ports
	// TODO initialize EEPROM
	// TODO initialize PWM Generator
	// TODO initialize I2C Bus
	// TODO initialize Timer
	// TODO initialize PPM Controller
	// TODO invoke ~~MultiWii~~ FlightController setup
	// TODO invoke peripheral setup functions
}

[[noreturn]] void Main::loop() noexcept {
	for (;;) {
		// the main loop
	}
}
