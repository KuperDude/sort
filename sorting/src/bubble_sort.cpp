#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template<typename T> void bubble_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();

    for (int i = 0; i < arr_size - 1; i++) {
		for (int j = 0; j < arr_size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}