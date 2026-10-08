#include "natural_merge_sort.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

template<typename T>
void natural_merge_sort(const std::string& input_file, const std::string& output_file) {
    // Natural merge: detect already sorted runs

    std::ifstream in(input_file);
    if (!in.is_open()) return;

    std::vector<std::string> temp_files;
    std::vector<T> run;
    T prev, value;
    int file_id = 0;
    bool first = true;

    while (in >> value) {
        if (first) {
            run.push_back(value);
            prev = value;
            first = false;
            continue;
        }

        if (value >= prev) {
            run.push_back(value);
            prev = value;
        }
        else {
            // end of natural run
            std::string name = "natural_run_" + std::to_string(file_id++) + ".tmp";
            std::ofstream out(name);
            for (auto v : run) out << v << " ";
            out.close();
            temp_files.push_back(name);

            run.clear();
            run.push_back(value);
            prev = value;
        }
    }
    if (!run.empty()) {
        std::string name = "natural_run_" + std::to_string(file_id++) + ".tmp";
        std::ofstream out(name);
        for (auto v : run) out << v << " ";
        out.close();
        temp_files.push_back(name);
    }
    in.close();

    // Merge the natural runs
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
        if (!(streams[best] >> current[best])) active[best] = false;
    }
    out.close();

    for (const auto& f : temp_files) std::remove(f.c_str());
}

template void natural_merge_sort<int>(const std::string&, const std::string&);
template void natural_merge_sort<double>(const std::string&, const std::string&);