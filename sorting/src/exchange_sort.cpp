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

template<typename T> void exchange_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();
    int currentI = 0;
    while(!isSorted(arr) && currentI < arr_size) {
        for (int i = currentI+1; i < arr_size; i++) {
            if (arr[currentI] > arr[i]) {
                temp = arr[currentI];
                arr[currentI] = arr[i];
                arr[i] = temp;
            }
        }
        currentI++;
    }
}