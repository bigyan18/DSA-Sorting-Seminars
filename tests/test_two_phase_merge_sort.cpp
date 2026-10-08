#include <catch.hpp>
#include "two_phase_merge_sort.h"
#include <fstream>
#include <vector>
#include <string>

void write_file(const std::string& name, const std::vector<int>& data) {
    std::ofstream out(name);
    for (int x : data) out << x << " ";
}

std::vector<int> read_file(const std::string& name) {
    std::ifstream in(name);
    std::vector<int> res;
    int x;
    while (in >> x) res.push_back(x);
    return res;
}

TEST_CASE("Two-phase merge - empty", "[two_phase]") {
    write_file("in_empty.txt", {});
    two_phase_merge_sort<int>("in_empty.txt", "out_empty.txt");
    REQUIRE(read_file("out_empty.txt").empty());
}

TEST_CASE("Two-phase merge - single element", "[two_phase]") {
    write_file("in_single.txt", { 42 });
    two_phase_merge_sort<int>("in_single.txt", "out_single.txt");
    REQUIRE(read_file("out_single.txt") == std::vector<int>{42});
}

TEST_CASE("Two-phase merge - reverse", "[two_phase]") {
    write_file("in_rev.txt", { 5, 4, 3, 2, 1 });
    two_phase_merge_sort<int>("in_rev.txt", "out_rev.txt");
    REQUIRE(read_file("out_rev.txt") == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Two-phase merge - random", "[two_phase]") {
    write_file("in_rand.txt", { 3, 1, 4, 1, 5, 9, 2, 6 });
    two_phase_merge_sort<int>("in_rand.txt", "out_rand.txt");
    REQUIRE(read_file("out_rand.txt") == std::vector<int>{1, 1, 2, 3, 4, 5, 6, 9});
}