#include "two_phase_merge_sort.h"
#include <fstream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

template<typename T>
void two_phase_merge_sort(const std::string& input_file, const std::string& output_file) {
    const size_t RUN_SIZE = 1024;   // size of one run that fits in memory

    std::ifstream in(input_file);
    if (!in.is_open()) return;

    std::vector<std::string> temp_files;
    std::vector<T> run;
    T value;
    int file_id = 0;

    // ========== Phase 1: Create sorted runs ==========
    while (in >> value) {
        run.push_back(value);
        if (run.size() == RUN_SIZE) {
            std::sort(run.begin(), run.end());
            std::string temp_name = "temp_run_" + std::to_string(file_id++) + ".tmp";
            std::ofstream out(temp_name);
            for (const auto& v : run) out << v << " ";
            out.close();
            temp_files.push_back(temp_name);
            run.clear();
        }
    }
    // last incomplete run
    if (!run.empty()) {
        std::sort(run.begin(), run.end());
        std::string temp_name = "temp_run_" + std::to_string(file_id++) + ".tmp";
        std::ofstream out(temp_name);
        for (const auto& v : run) out << v << " ";
        out.close();
        temp_files.push_back(temp_name);
    }
    in.close();

    if (temp_files.empty()) {
        // empty input → create empty output
        std::ofstream out(output_file);
        return;
    }

    // ========== Phase 2: Multi-way merge ==========
    using Pair = std::pair<T, size_t>;
    auto cmp = [](const Pair& a, const Pair& b) { return a.first > b.first; };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq(cmp);

    std::vector<std::ifstream> streams(temp_files.size());
    for (size_t i = 0; i < temp_files.size(); ++i) {
        streams[i].open(temp_files[i]);
        if (streams[i] >> value) {
            pq.push({ value, i });
        }
    }

    std::ofstream out(output_file);
    while (!pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();
        out << val << " ";
        if (streams[idx] >> value) {
            pq.push({ value, idx });
        }
    }
    out.close();

    // clean temporary files
    for (const auto& f : temp_files) {
        std::remove(f.c_str());
    }
}

template void two_phase_merge_sort<int>(const std::string&, const std::string&);
template void two_phase_merge_sort<double>(const std::string&, const std::string&);