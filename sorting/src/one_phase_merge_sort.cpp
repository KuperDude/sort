#include <iostream>
#include <iterator>
#include <array>

using namespace std;

template <typename T> void one_phase_merge_sort(T& arr) {
    T temp = arr;

    for (int width = 1; width < arr.size(); width *= 2) {
        for (int i = 0; i < arr.size(); i += 2 * width) {
            int left = i;
            int mid = min(i + width, int(arr.size()));
            int right = min(i + 2 * width, int(arr.size()));

            int l = left, r = mid, k = left;

            while (l < mid && r < right) {
                if (arr[l] <= arr[r]) {
                    temp[k++] = arr[l++];
                }
                else {
                    temp[k++] = arr[r++];
                }
            }

            while (l < mid) {
                temp[k++] = arr[l++];
            }

            while (r < right) {
                temp[k++] = arr[r++];
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }
    }
}