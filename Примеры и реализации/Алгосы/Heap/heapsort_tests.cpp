#include "heap.hpp"
#include "heap_sort.hpp"
#include <cstddef>
#include <iostream>

using namespace std;

int main() {
    
    size_t n;
    cin >> n;

    int* arr = new int[n];

    for (size_t i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr[i] = element;
    }

    HeapSort_n(arr, n);

    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}