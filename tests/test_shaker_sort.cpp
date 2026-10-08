#include <catch.hpp>
#include "shaker_sort.h"
#include <vector>

TEST_CASE("Shaker Sort - empty", "[shaker]") {
    std::vector<int> arr;
    shaker_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Shaker Sort - single element", "[shaker]") {
    std::vector<int> arr = { 42 };
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Shaker Sort - already sorted", "[shaker]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Shaker Sort - reverse sorted", "[shaker]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Shaker Sort - random with duplicates", "[shaker]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}