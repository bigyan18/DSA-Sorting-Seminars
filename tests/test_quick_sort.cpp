#include <catch.hpp>
#include "quick_sort.h"
#include <vector>

TEST_CASE("Quick Sort - empty", "[quick]") {
    std::vector<int> arr;
    quick_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Quick Sort - single element", "[quick]") {
    std::vector<int> arr = { 42 };
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Quick Sort - already sorted", "[quick]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Quick Sort - reverse sorted", "[quick]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Quick Sort - random with duplicates", "[quick]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}