#include "Sorts.h"
#include "Time.h"

#include <iostream>
#include <random>

int main() {
	std::random_device r;
	const int size = 100000;
	int arr[size];
	for (size_t i = 0; i < size; i++) {
		arr[i] = (int)r() % 10000;
	}
	int copy_arr[size];

	std::cout << "\nTest sorts\n";
	std::cout << "\n******************************************************************\n\n";

	std::cout << "Array of 100000 elements, random filling, number spread (-10 000; 10 000)\n\n";

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("counting_sort() time");
		counting_sort(copy_arr, size);
	}
	sort_error(copy_arr, size);

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("quick_sort() time");
		quick_sort(copy_arr, 0, size - 1);
	}
	sort_error(copy_arr, size);

	std::cout << "\n******************************************************************\n\n";

	for (size_t i = 0; i < size; i++) {
		arr[i] = (int)r() % 400000;
	}

	std::cout << "Array of 100000 elements, random filling, number spread (-400 000; 400 000)\n\n";

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("counting_sort() time");
		counting_sort(copy_arr, size);
	}
	sort_error(copy_arr, size);

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("quick_sort() time");
		quick_sort(copy_arr, 0, size - 1);
	}
	sort_error(copy_arr, size);

	std::cout << "\n******************************************************************\n\n";
	
	for (size_t i = 0; i < size; i++) {
		arr[i] = (int)r() % 1000000;
	}

	std::cout << "Array of 100000 elements, random filling, number spread (-1 000 000; 1 000 000)\n\n";

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("counting_sort() time");
		counting_sort(copy_arr, size);
	}
	sort_error(copy_arr, size);

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("quick_sort() time");
		quick_sort(copy_arr, 0, size - 1);
	}
	sort_error(copy_arr, size);

	std::cout << "\n******************************************************************\n\n";

	for (size_t i = 0; i < size; i++) {
		arr[i] = i;
	}

	std::cout << "Array of 100000 elements, already sorted, number spread (0; 100 000)\n\n";

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("counting_sort() time");
		counting_sort(copy_arr, size);
	}
	sort_error(copy_arr, size);

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("quick_sort() time");
		quick_sort(copy_arr, 0, size - 1);
	}
	sort_error(copy_arr, size);

	std::cout << "\n******************************************************************\n\n";
	
	
	for (size_t i = 0; i < size; i++) {
		arr[i] = i * 10;
	}

	std::cout << "Array of 100000 elements, already sorted, number spread (0; 1 000 000)\n\n";

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("counting_sort() time");
		counting_sort(copy_arr, size);
	}
	sort_error(copy_arr, size);

	memcpy(copy_arr, arr, sizeof(copy_arr));
	{
		Time t("quick_sort() time");
		quick_sort(copy_arr, 0, size - 1);
	}
	sort_error(copy_arr, size);

	std::cout << "\n******************************************************************\n\n";
	
	system("pause");
}