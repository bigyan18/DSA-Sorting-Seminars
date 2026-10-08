#include <catch.hpp>
#include "bubble_sort.h"
#include <vector>

TEST_CASE("Bubble Sort - empty", "[bubble]") {
    std::vector<int> arr;
    bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Bubble Sort - single element", "[bubble]") {
    std::vector<int> arr = { 42 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Bubble Sort - already sorted", "[bubble]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Bubble Sort - reverse sorted", "[bubble]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Bubble Sort - random with duplicates", "[bubble]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}