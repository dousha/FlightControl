//
// Created by dousha on 2019/9/4.
//

#ifndef FLIGHTCONTROL_RINGBUFFER_H
#define FLIGHTCONTROL_RINGBUFFER_H

#include <array>

template<typename ElementType>
class RingBuffer {
public:
	explicit RingBuffer(const int size);

	~RingBuffer();

	ElementType poll();

	ElementType peek();

	void put(ElementType element);

	bool is_empty();

	bool is_full();

private:
	size_t size;
	size_t readIndex;
	size_t writeIndex;
	ElementType container[];
};

template<typename ElementType>
RingBuffer<ElementType>::RingBuffer(const int size) {
	this->container = new ElementType[size];
	readIndex = 0;
	writeIndex = 0;
}

template<typename ElementType>
ElementType RingBuffer<ElementType>::poll() {
	ElementType ele = container[readIndex];
	if (++readIndex == size) {
		readIndex = 0;
	}
	return ele;
}

template<typename ElementType>
ElementType RingBuffer<ElementType>::peek() {
	return container[readIndex];
}

template<typename ElementType>
RingBuffer<ElementType>::~RingBuffer() {
	delete[](this->container);
}

template<typename ElementType>
void RingBuffer<ElementType>::put(ElementType element) {
	container[writeIndex] = element;
	if (++writeIndex == size) {
		writeIndex = 0;
	}
}

template<typename ElementType>
bool RingBuffer<ElementType>::is_empty() {
	return readIndex == writeIndex;
}

template<typename ElementType>
bool RingBuffer<ElementType>::is_full() {
	return readIndex == 0 ? writeIndex == size - 1 : writeIndex == readIndex - 1;
}


#endif //FLIGHTCONTROL_RINGBUFFER_H
