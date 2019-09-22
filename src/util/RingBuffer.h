//
// Created by dousha on 2019/9/4.
//

#ifndef FLIGHTCONTROL_RINGBUFFER_H
#define FLIGHTCONTROL_RINGBUFFER_H

#include <array>

template<typename ElementType, size_t size>
class RingBuffer {
public:
	ElementType poll() {
		ElementType element = container[readIndex];
		if (++readIndex == size) {
			readIndex = 0;
		}
		return element;
	}

	ElementType peek() {
		return container[readIndex];
	}

	void put(ElementType element) {
		container[writeIndex] = element;
		if (++writeIndex == size) {
			writeIndex = 0;
		}
	}

	ElementType shift(ElementType element) {
		ElementType result = nullptr;
		if (is_full()) {
			result = poll();
		}
		put(element);
		return result;
	}

	void populate(ElementType element) {
		clear();
		while (!is_full()) {
			put(element);
		}
		clear(); // this will not discard elements, it just resets the pointers
	}

	bool is_empty() {
		return readIndex == writeIndex;
	}

	bool is_full() {
		return readIndex == 0 ? writeIndex == size - 1 : writeIndex == readIndex - 1;
	}

	size_t capacity() {
		return size;
	}

	size_t count() {
		return writeIndex > readIndex ? writeIndex - readIndex : size - (readIndex - writeIndex);
	}

	void clear() {
		writeIndex = readIndex = 0;
	}

	ElementType operator[](size_t index) {
		return container[(readIndex + index) % size];
	}

private:
	size_t readIndex = 0;
	size_t writeIndex = 0;
	std::array<ElementType, size> container = std::array<ElementType, size>();
};

#endif //FLIGHTCONTROL_RINGBUFFER_H
