//
// Created by 李家豪 on 2019/9/22.
//

#ifndef FLIGHTCONTROL_BOX_H
#define FLIGHTCONTROL_BOX_H

template <typename NumberType>
class Box {
public:
	Box() = default;

	void chain(Box &next) {
		nextBox = next;
	}

	NumberType calc(NumberType x) = 0;

private:
	Box& nextBox = nullptr;
};


#endif //FLIGHTCONTROL_BOX_H
