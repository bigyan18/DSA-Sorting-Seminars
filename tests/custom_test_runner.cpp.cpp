#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <functional>
#include <fstream>
#include <filesystem>

#include "insertion_sort.h"
#include "selection_sort.h"
#include "exchange_sort.h"
#include "bubble_sort.h"
#include "optimized_bubble_sort.h"
#include "binary_insertion_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "two_phase_merge_sort.h"
#include "one_phase_merge_sort.h"
#include "natural_merge_sort.h"

using namespace std;
using namespace std::chrono;

template<typename T>
bool is_sorted(const vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i)
        if (arr[i] < arr[i - 1]) return false;
    return true;
}

struct TestResult {
    string description;
    bool passed;
    double time_us;
};

template<typename Func>
TestResult run_single_test(Func sort_func, vector<int> data, const string& description) {
    auto start = high_resolution_clock::now();
    sort_func(data);
    auto end = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(end - start).count() / 1000.0;
    return { description, is_sorted(data), us };
}

// Special version for external sorts (they work with files)
TestResult run_external_test(function<void(const string&, const string&)> sort_func,
    const vector<int>& data, const string& description) {

    // write input file
    ofstream out("temp_in.txt");
    for (int x : data) out << x << " ";
    out.close();

    auto start = high_resolution_clock::now();
    sort_func("temp_in.txt", "temp_out.txt");
    auto end = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(end - start).count() / 1000.0;

    // read result
    ifstream in("temp_out.txt");
    vector<int> result;
    int x;
    while (in >> x) result.push_back(x);

    return { description, is_sorted(result), us };
}

void print_test(const TestResult& r) {
    cout << (r.passed ? "[PASS] " : "[FAIL] ")
        << left << setw(48) << r.description;

    int filled = r.passed ? 8 : 2;
    for (int i = 0; i < 8; ++i)
        cout << (i < filled ? '#' : '.');

    cout << "  " << right << setw(7) << fixed << setprecision(1) << r.time_us << " us\n";
}

void run_algorithm(const string& name, function<void(vector<int>&)> sort_func) {
    cout << "\n" << name << "\n";
    vector<TestResult> results;

    results.push_back(run_single_test(sort_func, {}, "empty array stays empty"));
    results.push_back(run_single_test(sort_func, { 42 }, "single element array is unchanged"));
    results.push_back(run_single_test(sort_func, { 1,2,3,4,5 }, "already sorted array stays sorted"));
    results.push_back(run_single_test(sort_func, { 5,4,3,2,1 }, "reverse sorted array is sorted correctly"));
    results.push_back(run_single_test(sort_func, { 3,1,4,1,5,9,2,6,5 }, "array with duplicates sorts correctly"));
    results.push_back(run_single_test(sort_func, { 1,8,19,3,12,16,9,5 }, "individual variant sorts correctly"));

    double total = 0;
    int passed = 0;
    for (const auto& r : results) {
        print_test(r);
        total += r.time_us;
        if (r.passed) passed++;
    }
    cout << "Total time: " << fixed << setprecision(1) << total
        << " us   " << passed << "/" << results.size() << " passed\n";
}

void run_external_algorithm(const string& name, function<void(const string&, const string&)> sort_func) {
    cout << "\n" << name << "\n";
    vector<TestResult> results;

    results.push_back(run_external_test(sort_func, {}, "empty array stays empty"));
    results.push_back(run_external_test(sort_func, { 42 }, "single element array is unchanged"));
    results.push_back(run_external_test(sort_func, { 1,2,3,4,5 }, "already sorted array stays sorted"));
    results.push_back(run_external_test(sort_func, { 5,4,3,2,1 }, "reverse sorted array is sorted correctly"));
    results.push_back(run_external_test(sort_func, { 3,1,4,1,5,9,2,6,5 }, "array with duplicates sorts correctly"));
    results.push_back(run_external_test(sort_func, { 1,8,19,3,12,16,9,5 }, "individual variant sorts correctly"));

    double total = 0;
    int passed = 0;
    for (const auto& r : results) {
        print_test(r);
        total += r.time_us;
        if (r.passed) passed++;
    }
    cout << "Total time: " << fixed << setprecision(1) << total
        << " us   " << passed << "/" << results.size() << " passed\n";
}

int main() {
    cout << "===== Sorting Algorithms Test Runner (All 12) =====\n";

    // Seminar 1
    run_algorithm("bubbleSort", bubble_sort<int>);
    run_algorithm("exchangeSort", exchange_sort<int>);
    run_algorithm("insertionSort", insertion_sort<int>);
    run_algorithm("optimizedBubbleSort", optimized_bubble_sort<int>);
    run_algorithm("selectionSort", selection_sort<int>);

    // Seminar 2
    run_algorithm("binaryInsertionSort", binary_insertion_sort<int>);
    run_algorithm("shakerSort", shaker_sort<int>);

    // Seminar 3
    run_algorithm("shellSort", shell_sort<int>);
    run_algorithm("quickSort", quick_sort<int>);

    // Seminar 4 - External
    run_external_algorithm("twoPhaseMergeSort", two_phase_merge_sort<int>);
    run_external_algorithm("onePhaseMergeSort", one_phase_merge_sort<int>);
    run_external_algorithm("naturalMergeSort", natural_merge_sort<int>);

    cout << "\n===== All 12 algorithms tested =====\n";
    system("pause");
    return 0;
}