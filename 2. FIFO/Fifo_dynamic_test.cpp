#include "Fifo_dynamic.h"

int main() {
	size_t capacity;
	std::cout << "Enter capacity queue: ";
	std::cin >> capacity;
	
	std::cout << "\nTest for Fifo_dynamic with capacity of " << capacity << " elements" << std::endl << std::endl;
	
	Fifo2<char> queue(capacity);
	std::cout << "Call empty() return:  " << queue.empty() << std::endl;
	std::cout << "**********************************" << std::endl;
	for (size_t i = 97; i < 104; i++) {
		if(queue.add((char)i) == true) {
			std::cout << "Add element: " << queue.back() << "\t size queue: " << queue.size() << std::endl;
		}
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