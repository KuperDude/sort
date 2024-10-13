#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template<typename T> bool isSorted(T& arr) {
    int arr_size = arr.size();
    for (int i = 0; i < arr_size-1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

template<typename T> void optimized_bubble_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();

    while(!isSorted(arr)) {
        for (int i = 0; i < arr_size-1; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}