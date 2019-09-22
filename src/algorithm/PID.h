//
// Created by 李家豪 on 2019/9/22.
//

#ifndef FLIGHTCONTROL_PID_H
#define FLIGHTCONTROL_PID_H

template <typename NumberType, NumberType neutralValue = 0>
class PID {
public:
	PID() = default;
	PID(NumberType p) {
		kP = p;
	}

	PID(NumberType p, NumberType d) {
		kP = p;
		kD = d;
	}

	PID(NumberType p, NumberType i, NumberType d) {
		kP = p;
		kI = i;
		kD = d;
	}

	void set_proportion(NumberType p) {
		kP = p;
	}

	void set_integral(NumberType i) {
		kI = i;
	}

	void set_derivative(NumberType d) {
		kD = d;
	}

	void clear_integral() {
		integralValue = neutralValue;
	}

	void clear_derivative() {
		lastOutputValue = neutralValue;
	}

	NumberType calc(NumberType h) {
		NumberType p = h * kP;
		NumberType i = (integralValue += h) * kI;
		NumberType d = (lastOutputValue - h) * kD;
		return p + i + d;
	}

private:
	NumberType kP = 0;
	NumberType kI = 0;
	NumberType kD = 0;
	NumberType integralValue = neutralValue;
	NumberType lastOutputValue = neutralValue;
};

#endif //FLIGHTCONTROL_PID_H
