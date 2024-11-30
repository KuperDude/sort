#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template <typename T> int partition(T& arr, int low, int high) {
    typename T::value_type temp = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < temp) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T> void quick_sort(T& arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
