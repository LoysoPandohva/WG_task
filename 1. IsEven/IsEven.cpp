#include <iostream>

bool isEven(int value) { return !(value & 1); }

int main() {
	int num;
	
	while(true){
		std::cout << "Enter number: ";
		std::cin >> num;
		if (isEven(num)) {
			std::cout << num << " is even number \n";
		}
		else std::cout << num << " is uneven number \n";
	}
	
	system("pause");
}