#include <iostream>
#include <cstdlib>

template<class T>
struct Fifo_static {
	Fifo_static() :first_el(0), last_el(0), count_el(0) {}

	void add(const T& value) {
		if (count_el != 0) {
			last_el = cicl_index(++last_el);
			if (last_el == first_el) {
				first_el = cicl_index(++first_el);
			}
		}
		buf[last_el] = value;
		if (count_el < capacity) count_el++;
	}
	const T& pop() {
		test_for_empty();
		size_t old_first_el = first_el;
		first_el = cicl_index(++first_el);
		count_el--;
		if (count_el == 0) {
			first_el = 0;
			last_el = 0;
		}
		return buf[old_first_el];
	}

	const T& front() {
		test_for_empty();
		return buf[first_el];
	}
	const T& back() {
		test_for_empty();
		return buf[last_el];
	}

	void clear() {
		count_el = 0;
		first_el = 0;
		last_el = 0;
	}
	bool empty() { return count_el == 0; }
	size_t size() { return count_el; }
private:
	static const int capacity = 5;
	T buf[capacity];
	size_t first_el;
	size_t last_el;
	size_t count_el;

	void test_for_empty() {
		if (count_el == 0) {
			std::cout << "[ERROR] Queue is empty! \n";
			std::abort();
		}
	}
	size_t cicl_index(size_t index) {
		if (index < 0) return index = capacity - 1;
		else return index % capacity;
	}
};