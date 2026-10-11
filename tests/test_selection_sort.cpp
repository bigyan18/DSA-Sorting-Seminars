#include <catch.hpp>
#include "selection_sort.h"
#include <vector>

TEST_CASE("Selection Sort - empty", "[selection]") {
    std::vector<int> arr;
    selection_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Selection Sort - single element", "[selection]") {
    std::vector<int> arr = { 42 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Selection Sort - already sorted", "[selection]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Selection Sort - reverse sorted", "[selection]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Selection Sort - random with duplicates", "[selection]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("Selection Sort - individual variant", "[selection]") {
    std::vector<int> arr = { 1, 8, 19, 3, 12, 16, 9, 5 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 3, 5, 8, 9, 12, 16, 19});
}