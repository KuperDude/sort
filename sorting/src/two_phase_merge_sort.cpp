#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
std::vector<std::pair<size_t, size_t>> split_into_runs(const T& arr) {
    std::vector<std::pair<size_t, size_t>> runs;
    size_t start = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            runs.emplace_back(start, i);
            start = i;
        }
    }
    runs.emplace_back(start, arr.size());
    return runs;
}

template <typename T>
void merge_runs(T& arr, typename T::value_type* temp, size_t left_start, size_t left_end, size_t right_start, size_t right_end) {
    size_t i = left_start, j = right_start, k = left_start;

    while (i < left_end && j < right_end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i < left_end) temp[k++] = arr[i++];
    while (j < right_end) temp[k++] = arr[j++];

    for (size_t l = left_start; l < right_end; ++l) {
        arr[l] = temp[l];
    }
}

template <typename T>
void two_phase_merge_sort(T& arr) {
    auto temp = new typename T::value_type[arr.size()];

    auto runs = split_into_runs(arr);

    while (runs.size() > 1) {
        vector<pair<size_t, size_t>> new_runs;

        for (size_t i = 0; i < runs.size(); i += 2) {
            if (i + 1 < runs.size()) {
                merge_runs(arr, temp, runs[i].first, runs[i].second, runs[i + 1].first, runs[i + 1].second);
                new_runs.emplace_back(runs[i].first, runs[i + 1].second);
            } else {
                new_runs.push_back(runs[i]);
            }
        }
        runs = move(new_runs);
    }

    delete[] temp;
}

// int main() {
//     array<int, 6> arr = {9, 8, 7, 6, 5, 4};

//     two_phase_merge_sort(arr);

//     for (int i = 0; i < 6; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }