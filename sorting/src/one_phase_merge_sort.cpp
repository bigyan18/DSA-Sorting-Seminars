#include "one_phase_merge_sort.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

template<typename T>
void one_phase_merge_sort(const std::string& input_file, const std::string& output_file) {
    // For practical purposes we read everything into memory in runs
    // and merge them in one phase using temporary files.

    const size_t RUN_SIZE = 1024;

    std::ifstream in(input_file);
    if (!in.is_open()) return;

    std::vector<std::string> temp_files;
    std::vector<T> run;
    T value;
    int file_id = 0;

    while (in >> value) {
        run.push_back(value);
        if (run.size() == RUN_SIZE) {
            std::sort(run.begin(), run.end());
            std::string name = "one_phase_run_" + std::to_string(file_id++) + ".tmp";
            std::ofstream out(name);
            for (auto v : run) out << v << " ";
            out.close();
            temp_files.push_back(name);
            run.clear();
        }
    }
    if (!run.empty()) {
        std::sort(run.begin(), run.end());
        std::string name = "one_phase_run_" + std::to_string(file_id++) + ".tmp";
        std::ofstream out(name);
        for (auto v : run) out << v << " ";
        out.close();
        temp_files.push_back(name);
    }
    in.close();

    // One-phase style: merge all runs into the final file
    std::ofstream out(output_file);
    std::vector<std::ifstream> streams(temp_files.size());
    std::vector<T> current(temp_files.size());
    std::vector<bool> active(temp_files.size(), false);

    for (size_t i = 0; i < temp_files.size(); ++i) {
        streams[i].open(temp_files[i]);
        if (streams[i] >> current[i]) active[i] = true;
    }

    while (true) {
        int best = -1;
        for (size_t i = 0; i < temp_files.size(); ++i) {
            if (active[i] && (best == -1 || current[i] < current[best])) {
                best = static_cast<int>(i);
            }
        }
        if (best == -1) break;

        out << current[best] << " ";
        if (!(streams[best] >> current[best])) {
            active[best] = false;
        }
    }
    out.close();

    for (const auto& f : temp_files) std::remove(f.c_str());
}

template void one_phase_merge_sort<int>(const std::string&, const std::string&);
template void one_phase_merge_sort<double>(const std::string&, const std::string&);