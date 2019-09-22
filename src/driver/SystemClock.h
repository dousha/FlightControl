//
// Created by 李家豪 on 2019/9/19.
//

#ifndef FLIGHTCONTROL_SYSTEMCLOCK_H
#define FLIGHTCONTROL_SYSTEMCLOCK_H

#include <driverlib/sysctl.h>
#include "HardwareSpec.h"

class SystemClock {
public:
	SystemClock(uint64_t crystalFrequency, uint16_t division);
	void enablePeripheral(address_t address);
	void delay(uint32_t ms);
};


#endif //FLIGHTCONTROL_SYSTEMCLOCK_H
