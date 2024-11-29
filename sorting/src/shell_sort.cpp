#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template<typename T> void shell_sort(T& arr) {
    typename T::value_type temp;
    for (int mid = arr.size() / 2; mid > 0; mid /= 2) {
        for (int i = mid; i < arr.size(); i++) {
            temp = arr[i];
            int j;

            for (j = i; j >= mid && arr[j - mid] > temp; j -= mid) {
                arr[j] = arr[j - mid];
            }
            arr[j] = temp;
        }
    }
}