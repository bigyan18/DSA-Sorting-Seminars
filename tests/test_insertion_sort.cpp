#include <catch.hpp>
#include "insertion_sort.h"
#include <vector>

TEST_CASE("Insertion Sort - empty array", "[insertion]") {
    std::vector<int> arr;
    insertion_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Insertion Sort - single element", "[insertion]") {
    std::vector<int> arr = { 42 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Insertion Sort - already sorted", "[insertion]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Insertion Sort - reverse sorted", "[insertion]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Insertion Sort - random with duplicates", "[insertion]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}