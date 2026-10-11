#include <catch.hpp>
#include "exchange_sort.h"
#include <vector>

TEST_CASE("Exchange Sort - empty", "[exchange]") {
    std::vector<int> arr;
    exchange_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Exchange Sort - single element", "[exchange]") {
    std::vector<int> arr = { 42 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Exchange Sort - already sorted", "[exchange]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Exchange Sort - reverse sorted", "[exchange]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Exchange Sort - random with duplicates", "[exchange]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("Exchange Sort - individual variant", "[exchange]") {
    std::vector<int> arr = { 1, 8, 19, 3, 12, 16, 9, 5 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 3, 5, 8, 9, 12, 16, 19});
}