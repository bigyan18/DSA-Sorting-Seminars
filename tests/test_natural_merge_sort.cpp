#include <catch.hpp>
#include "natural_merge_sort.h"
#include <fstream>
#include <vector>
#include <string>

static void write_file(const std::string& name, const std::vector<int>& data) {
    std::ofstream out(name);
    for (int x : data) out << x << " ";
}

static std::vector<int> read_file(const std::string& name) {
    std::ifstream in(name);
    std::vector<int> res;
    int x;
    while (in >> x) res.push_back(x);
    return res;
}

TEST_CASE("Natural merge - empty", "[natural]") {
    write_file("in_nat_empty.txt", {});
    natural_merge_sort<int>("in_nat_empty.txt", "out_nat_empty.txt");
    REQUIRE(read_file("out_nat_empty.txt").empty());
}

TEST_CASE("Natural merge - single element", "[natural]") {
    write_file("in_nat_single.txt", { 42 });
    natural_merge_sort<int>("in_nat_single.txt", "out_nat_single.txt");
    REQUIRE(read_file("out_nat_single.txt") == std::vector<int>{42});
}

TEST_CASE("Natural merge - already sorted", "[natural]") {
    write_file("in_nat_sorted.txt", { 1, 2, 3, 4, 5 });
    natural_merge_sort<int>("in_nat_sorted.txt", "out_nat_sorted.txt");
    REQUIRE(read_file("out_nat_sorted.txt") == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Natural merge - reverse sorted", "[natural]") {
    write_file("in_nat_rev.txt", { 5, 4, 3, 2, 1 });
    natural_merge_sort<int>("in_nat_rev.txt", "out_nat_rev.txt");
    REQUIRE(read_file("out_nat_rev.txt") == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Natural merge - random with duplicates", "[natural]") {
    write_file("in_nat_rand.txt", { 3, 1, 4, 1, 5, 9, 2, 6, 5 });
    natural_merge_sort<int>("in_nat_rand.txt", "out_nat_rand.txt");
    REQUIRE(read_file("out_nat_rand.txt") == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}