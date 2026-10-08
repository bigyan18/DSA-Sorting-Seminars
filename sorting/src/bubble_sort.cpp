#include "bubble_sort.h"
#include <algorithm>

template<typename T>
void bubble_sort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j + 1 < arr.size() - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubble_sort<int>(std::vector<int>&);
template void bubble_sort<double>(std::vector<double>&);