#define CATCH_CONFIG_MAIN

#include "../catch2/catch.hpp"
#include "../sorting/include/bubble_sort.h"


TEST_CASE() {
    array<int, 6> arr = {9, 8, 7, 6, 5, 4};
	bubble_sort(arr);
	for (int i = 0; i < arr.size() - 1; i++) {
		REQUIRE(arr[i] <= arr[i+1]);
	}
    
	array<int, 6> arr2 = {};
	bubble_sort(arr2);
	for (int i = 0; i < arr.size() - 1; i++) {
		REQUIRE(arr2[i] <= arr2[i + 1]);
	}

	array<double, 6> arr3 = {2.3, 5, -1, 8, -20, 0};
	bubble_sort(arr3);
	for (int i = 0; i < arr.size() - 1; i++) {
		REQUIRE(arr3[i] <= arr3[i + 1]);
	}
	
}