#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template<typename T> bool isSorted(T& arr) {
    int arr_size = arr.size();
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

template<typename T> void body(T& arr, int i) {
    typename T::value_type temp;
    if (arr[i] < arr[i-1]) {
        temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        if (i-1 != 0) {
            body(arr, i-1);
        }
    }
}

template<typename T> void insertion_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();
    int currentI = 1;
    
    while(!isSorted(arr) && currentI < arr_size) {
        if (arr[currentI] < arr[currentI-1]) {
            body(arr, currentI);
        }
        currentI++;
    }
}