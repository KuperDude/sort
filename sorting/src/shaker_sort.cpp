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

template<typename T> void shaker_sort(T& arr) {
	typename T::value_type temp;
    int arr_size = arr.size();
    int k = 0;
    while(!isSorted(arr)) {
        if (k%2 == 0) {
            for (int i = k/2; i < arr_size-1; i++) {
                if (arr[i] > arr[i+1]) {
                    temp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = temp;
                }
            }
        } else {
            for (int i = arr_size-1-k/2; i > 0; i--) {
                if (arr[i] < arr[i-1]) {
                    temp = arr[i-1];
                    arr[i-1] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i = 0; i<7; i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;
        k++;
    }
}