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

template<typename T> void binary(T& arr, int left, int right, int i) {
    typename T::value_type temp;
    int arr_size = arr.size();
    int mid = (left+right)/2;

    if (left >= right || arr[i] == arr[mid]) {
        if (arr[i] > arr[left]) {
            left++;
        }
        for (int j = i; left<j; j--) {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
        
    } else if (arr[i] < arr[mid]) {
        binary(arr, left, mid-1, i);
    } else {
        binary(arr, mid+1, right, i);
    }
}


template<typename T> void binary_insertion_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();
    int currentI = 1;
    
    while(!isSorted(arr) && currentI < arr_size) {
        binary(arr, 0, currentI-1, currentI);
        currentI++;
    }
}