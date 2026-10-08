#include "selection_sort.h"
#include <algorithm> // for std::swap

template<typename T>
void selection_sort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

template void selection_sort<int>(std::vector<int>&);
template void selection_sort<double>(std::vector<double>&);