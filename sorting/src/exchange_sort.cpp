#include "exchange_sort.h"
#include <algorithm>

template<typename T>
void exchange_sort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[i]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template void exchange_sort<int>(std::vector<int>&);
template void exchange_sort<double>(std::vector<double>&);