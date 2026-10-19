#include <utility>
#include "heap.cpp"
using namespace std;

bool IntGreater(const int& a, const int& b) { return a > b; }

// Версия на куче MinHeap<T>
// Время: O(n log n), Память: O(n)
void HeapSort_n(int* arr, int n) {
    MinHeap<int> heap(arr, n, IntGreater);
    
    for (int i = n - 1; i > 0; i--)
        arr[i] = heap.Pop();;
}

// Восстанавливаем инвариант max-heap для int
void SiftDown(int* arr, int heap_size, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l >= heap_size) return;
        int j = (r < heap_size && arr[r] > arr[l]) ? r : l;
        if (arr[j] <= arr[i]) return;
        swap(arr[j], arr[i]);
        i = j;
    }
}

// Версия на месте
// Время: O(n log n), Память: O(1)
void heapSort_1(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        SiftDown(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        SiftDown(arr, i, 0);
    }
}
