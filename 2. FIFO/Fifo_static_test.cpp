#include "Fifo_static.h"

int main() {
	std::cout << "Test for Fifo_static with capacity of 5 elements" << std::endl << std::endl;
	Fifo_static<int> queue;
	std::cout << "Call empty() return:  " << queue.empty() << std::endl;
	std::cout << "**********************************" << std::endl;
	for (size_t i = 1; i < 8; i++) {
		queue.add(i);
		std::cout << "Add element: " << queue.back() << "\t size queue: " << queue.size() << std::endl;
	}
	std::cout << "**********************************" << std::endl;
	for (size_t i = 0; i < 2; i++) {
		std::cout << "Pop element: " << queue.pop() << std::endl;
	}
	std::cout << "**********************************" << std::endl; 
	std::cout << "Front element: " << queue.front() << std::endl;
	std::cout << "Back element: " << queue.back() << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << "Size queue: " << queue.size() << std::endl;
	std::cout << "Call clear()..." << std::endl;
	queue.clear();
	std::cout << "Size queue: " << queue.size() << std::endl;
	std::cout << "**********************************" << std::endl;
	
	system("pause");
}