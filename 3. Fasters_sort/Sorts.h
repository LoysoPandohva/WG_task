#include <iostream>
#include <math.h>

bool sort_error(int arr[], size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			std::cout << "\nSORT ERROR!\n";
			return true;
		}
	}
	return false;
}

int get_max(int arr[], size_t size) {
	int max = arr[0];
	for (size_t i = 1; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int get_min(int arr[], size_t size) {
	int min = arr[0];
	for (size_t i = 1; i < size; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

/////////////////////////////////////////////

void counting_sort(int arr[], size_t size) {
	int min = get_min(arr, size);
	if (min < 0) {
		for (size_t i = 0; i < size; i++) {
			arr[i] += abs(min);
		}
	}
	int max = get_max(arr, size) + 1;
	int* count = new int[max];

	for (size_t i = 0; i < max; i++) {
		count[i] = 0;
	}

	for (size_t i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	size_t index = 0;
	for (int i = 0; i < max; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}

	if (min < 0) {
		for (size_t i = 0; i < size; i++) {
			arr[i] -= abs(min);
		}
	}

	delete[] count;
}

/////////////////////////////////////////////

template<class T>
void quick_sort(T arr[], int left, int right) {
	int l = left;
	int r = right;
	int mid = (arr[left] + arr[(l + r) / 2] + arr[right]) / 3;
	int count;
	while (l < r) {
		while (arr[l] < mid) l++;
		while (arr[r] > mid) r--;
		if (l <= r) {
			count = arr[l];
			arr[l] = arr[r];
			arr[r] = count;
			l++;
			r--;
		}
	}
	if (left < r) quick_sort(arr, left, r);
	if (l < right) quick_sort(arr, l, right);
}