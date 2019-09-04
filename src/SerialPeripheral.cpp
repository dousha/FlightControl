//
// Created by dousha on 2019/9/4.
//

#include "SerialPeripheral.h"

SerialPeripheral::SerialPeripheral(int port, int baud) {
	this->set(port, baud);
}
