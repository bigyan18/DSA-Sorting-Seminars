#include <catch.hpp>
#include "optimized_bubble_sort.h"
#include <vector>

TEST_CASE("Optimized Bubble Sort - empty", "[optimized_bubble]") {
    std::vector<int> arr;
    optimized_bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Optimized Bubble Sort - single element", "[optimized_bubble]") {
    std::vector<int> arr = { 42 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Optimized Bubble Sort - already sorted", "[optimized_bubble]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Optimized Bubble Sort - reverse sorted", "[optimized_bubble]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Optimized Bubble Sort - random with duplicates", "[optimized_bubble]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}