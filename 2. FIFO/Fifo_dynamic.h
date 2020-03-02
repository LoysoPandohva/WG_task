#include <iostream>
#include <cstdlib>

template<class T>
struct Fifo2 {
	Fifo2(size_t capacity = 256) : capacity(capacity), count_el(0) {
		buf = new T[capacity];
		begin = buf;
		end = begin + capacity;
		first_el = begin;
		last_el = begin;
	}
	~Fifo2() { delete[] buf; }

	bool add(const T& value) {
		if(count_el == capacity){
			std::cout << "[ERROR] Queue is full! \n";
			return false;
		}
		if (count_el != 0) {
			last_el = cicl_pointer(++last_el);
			if (last_el == first_el) {
				first_el = cicl_pointer(++first_el);
			}
		}
		*last_el = value;
		if (count_el < capacity) count_el++;
		return true;
	}
	const T& pop() {
		test_for_empty();
		T* old_first_el = first_el;
		first_el = cicl_pointer(++first_el);
		count_el--;
		if (count_el == 0) {
			first_el = begin;
			last_el = begin;
		}
		return *old_first_el;
	}

	const T& front() {
		test_for_empty();
		return *first_el;
	}
	const T& back() {
		test_for_empty();
		return *last_el;
	}

	void clear() {
		count_el = 0;
		first_el = begin;
		last_el = begin;
	}
	bool empty() { return count_el == 0; }
	size_t size() { return count_el; }

private:
	const size_t capacity;
	T* buf;
	T* begin;
	T* end;
	T* first_el;
	T* last_el;
	size_t count_el;

	void test_for_empty() {
		if (count_el == 0) {
			std::cout << "[ERROR] Queue is empty! \n";
			std::abort();
		}
	}
	T* cicl_pointer(T* element) {
		if (element < begin) return element = end;
		else if(element == end) return element = begin;
		else return element;
	}
};