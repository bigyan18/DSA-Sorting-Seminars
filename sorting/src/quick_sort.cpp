#include "quick_sort.h"
#include <algorithm>

template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];          // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
void quick_sort_helper(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

template<typename T>
void quick_sort(std::vector<T>& arr) {
    if (!arr.empty()) {
        quick_sort_helper(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

// Explicit instantiations
template void quick_sort<int>(std::vector<int>&);
template void quick_sort<double>(std::vector<double>&);