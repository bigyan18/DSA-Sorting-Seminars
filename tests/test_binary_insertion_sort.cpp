#include <catch.hpp>
#include "binary_insertion_sort.h"
#include <vector>

TEST_CASE("Binary Insertion Sort - empty", "[binary_insertion]") {
    std::vector<int> arr;
    binary_insertion_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Binary Insertion Sort - single element", "[binary_insertion]") {
    std::vector<int> arr = { 42 };
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Binary Insertion Sort - already sorted", "[binary_insertion]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Binary Insertion Sort - reverse sorted", "[binary_insertion]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Binary Insertion Sort - random with duplicates", "[binary_insertion]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("Binary Insertion Sort - individual variant", "[binary_insertion]") {
    std::vector<int> arr = { 1, 8, 19, 3, 12, 16, 9, 5 };
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 3, 5, 8, 9, 12, 16, 19});
}