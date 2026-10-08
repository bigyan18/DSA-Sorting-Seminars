#include "insertion_sort.h"

template<typename T>
void insertion_sort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Explicit instantiations
template void insertion_sort<int>(std::vector<int>&);
template void insertion_sort<double>(std::vector<double>&);