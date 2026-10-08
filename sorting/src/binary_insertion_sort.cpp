#include "binary_insertion_sort.h"

template<typename T>
void binary_insertion_sort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];

        // Binary search for the insertion position
        size_t left = 0;
        size_t right = i;

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (arr[mid] <= key)
                left = mid + 1;
            else
                right = mid;
        }

        // Shift elements to the right
        for (size_t j = i; j > left; --j) {
            arr[j] = arr[j - 1];
        }

        arr[left] = key;
    }
}

// Explicit instantiations
template void binary_insertion_sort<int>(std::vector<int>&);
template void binary_insertion_sort<double>(std::vector<double>&);