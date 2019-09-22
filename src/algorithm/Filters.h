//
// Created by 李家豪 on 2019/9/10.
//

#ifndef FLIGHTCONTROL_FILTERS_H
#define FLIGHTCONTROL_FILTERS_H

#include <cstddef>
#include "../util/RingBuffer.h"

template <typename T>
class Filters {
public:
	virtual void addDataPoint(T value) = 0;
	virtual void reset() = 0;
	virtual T predict() = 0;
protected:
	Filters() = default;
	~Filters() = default;
};

template <typename T, T neutralValue, size_t size>
class NaiveLowPassFilter : private Filters<T> {
public:
	explicit NaiveLowPassFilter(float p) {
		buffer.populate(neutralValue);
		param = p;
	}

	void addDataPoint(T value) {
		buffer.put(value);
	}

	void reset() {
		buffer.populate(neutralValue);
	}

	T predict() {
		return nullptr;
	}

	void set_param(float value) {
		param = value;
	}

private:
	RingBuffer<T, size> buffer = RingBuffer<T, size>();
	float param = 1.f;
};


#endif //FLIGHTCONTROL_FILTERS_H
