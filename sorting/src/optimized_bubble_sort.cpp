#include "optimized_bubble_sort.h"
#include <algorithm>

template<typename T>
void optimized_bubble_sort(std::vector<T>& arr) {
    bool swapped;
    size_t n = arr.size();
    do {
        swapped = false;
        for (size_t j = 0; j + 1 < n; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

template void optimized_bubble_sort<int>(std::vector<int>&);
template void optimized_bubble_sort<double>(std::vector<double>&);