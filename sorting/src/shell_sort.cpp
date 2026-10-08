#include "shell_sort.h"

template<typename T>
void shell_sort(std::vector<T>& arr) {
    size_t n = arr.size();

    // Start with a big gap, then reduce the gap
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (size_t i = gap; i < n; ++i) {
            T temp = arr[i];
            size_t j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Explicit instantiations
template void shell_sort<int>(std::vector<int>&);
template void shell_sort<double>(std::vector<double>&);