#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template<typename T> int findMin(T& arr, int startIndex) {
    int arr_size = arr.size();
    int result = startIndex;

    for (int i = startIndex + 1; i<arr_size; i++) {
        if (arr[result] > arr[i]) {
            result = i;
        }
    }

    return result;
}

template<typename T> void selection_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();

    for (int i = 0; i < arr_size - 1; i++) {
        int minIndex = findMin(arr, i);
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

