#define CATCH_CONFIG_MAIN

#include "../catch2/catch.hpp"
#include "../sorting/include/quick_sort.h"


TEST_CASE() {
    array<int, 6> arr = {9, 8, 7, 6, 5, 4};
	quick_sort(arr, 0, arr.size());
	for (int i = 0; i < arr.size() - 1; i++) {
		REQUIRE(arr[i] <= arr[i+1]);
	}
}

TEST_CASE() {
	array<int, 6> arr2 = {};
	quick_sort(arr2, 0, arr2.size());
	for (int i = 0; i < arr2.size() - 1; i++) {
		REQUIRE(arr2[i] <= arr2[i + 1]);
	}
}

TEST_CASE() {
	array<double, 6> arr3 = {2.3, 5, -1, 8, -20, 0};
	quick_sort(arr3, 0, arr3.size());
	for (int i = 0; i < arr3.size() - 1; i++) {
		REQUIRE(arr3[i] <= arr3[i + 1]);
	}
}