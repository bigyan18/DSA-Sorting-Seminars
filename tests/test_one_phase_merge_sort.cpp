#include <catch.hpp>
#include "one_phase_merge_sort.h"
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

TEST_CASE("One-phase merge - empty", "[one_phase]") {
    write_file("in_one_empty.txt", {});
    one_phase_merge_sort<int>("in_one_empty.txt", "out_one_empty.txt");
    REQUIRE(read_file("out_one_empty.txt").empty());
}

TEST_CASE("One-phase merge - single element", "[one_phase]") {
    write_file("in_one_single.txt", { 42 });
    one_phase_merge_sort<int>("in_one_single.txt", "out_one_single.txt");
    REQUIRE(read_file("out_one_single.txt") == std::vector<int>{42});
}

TEST_CASE("One-phase merge - already sorted", "[one_phase]") {
    write_file("in_one_sorted.txt", { 1, 2, 3, 4, 5 });
    one_phase_merge_sort<int>("in_one_sorted.txt", "out_one_sorted.txt");
    REQUIRE(read_file("out_one_sorted.txt") == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("One-phase merge - reverse sorted", "[one_phase]") {
    write_file("in_one_rev.txt", { 5, 4, 3, 2, 1 });
    one_phase_merge_sort<int>("in_one_rev.txt", "out_one_rev.txt");
    REQUIRE(read_file("out_one_rev.txt") == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("One-phase merge - random with duplicates", "[one_phase]") {
    write_file("in_one_rand.txt", { 3, 1, 4, 1, 5, 9, 2, 6, 5 });
    one_phase_merge_sort<int>("in_one_rand.txt", "out_one_rand.txt");
    REQUIRE(read_file("out_one_rand.txt") == std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9});
}