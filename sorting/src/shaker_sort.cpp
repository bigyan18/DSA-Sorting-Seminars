#include "shaker_sort.h"
#include <algorithm>

template<typename T>
void shaker_sort(std::vector<T>& arr) {
    if (arr.empty()) return;

    size_t left = 0;
    size_t right = arr.size() - 1;

    while (left < right) {
        // Forward pass (left → right)
        for (size_t i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
        --right;

        // Backward pass (right → left)
        for (size_t i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
            }
        }
        ++left;
    }
}

// Explicit instantiations
template void shaker_sort<int>(std::vector<int>&);
template void shaker_sort<double>(std::vector<double>&);