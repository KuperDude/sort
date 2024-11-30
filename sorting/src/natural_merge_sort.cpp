#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template <typename T> void natural_merge_sort(T& arr) {
    T temp = arr;

    while (true) {
        int left = 0, k = 0;
        bool sorted = true;

        while (left < arr.size()) {
            int mid = left + 1;
            while (mid < arr.size() && arr[mid - 1] <= arr[mid]) {
                mid++;
            }

            if (mid < arr.size()) {
                sorted = false;
            }

            int right = mid + 1;
            while (right < arr.size() && arr[right - 1] <= arr[right]) {
                right++;
            }

            int l = left, m = mid, r = left;

            while (l < mid && m < right) {
                temp[r++] = (arr[l] <= arr[m]) ? arr[l++] : arr[m++];
            }

            while (l < mid) {
                temp[r++] = arr[l++];
            }

            while (m < right) {
                temp[r++] = arr[m++];
            }

            left = right;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }

        if (sorted) {
            break;
        }
    }
}
