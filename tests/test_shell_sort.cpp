#define CATCH_CONFIG_MAIN

#include "../catch2/catch.hpp"
#include "../sorting/include/shell_sort.h"


TEST_CASE() {
    array<int, 6> arr = {9, 8, 7, 6, 5, 4};
	shell_sort(arr);
	for (int i = 0; i < arr.size() - 1; i++) {
		REQUIRE(arr[i] <= arr[i+1]);
	}
}
TEST_CASE() {
	array<int, 6> arr2 = {};
	shell_sort(arr2);
	for (int i = 0; i < arr2.size() - 1; i++) {
		REQUIRE(arr2[i] <= arr2[i + 1]);
	}
}
TEST_CASE() {
	array<double, 6> arr3 = {2.3, 5, -1, 8, -20, 0};
	shell_sort(arr3);
	for (int i = 0; i < arr3.size() - 1; i++) {
		REQUIRE(arr3[i] <= arr3[i + 1]);
	}
}