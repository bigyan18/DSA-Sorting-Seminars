#include <catch.hpp>
#include "shell_sort.h"
#include <vector>

TEST_CASE("Shell Sort - empty", "[shell]") {
    std::vector<int> arr;
    shell_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Shell Sort - single element", "[shell]") {
    std::vector<int> arr = { 42 };
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("Shell Sort - already sorted", "[shell]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Shell Sort - reverse sorted", "[shell]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Shell Sort - random with duplicates", "[shell]") {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("Shell Sort - individual variant", "[shell]") {
    std::vector<int> arr = { 1, 8, 19, 3, 12, 16, 9, 5 };
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 3, 5, 8, 9, 12, 16, 19});
}