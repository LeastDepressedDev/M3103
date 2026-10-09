/**
 * Алгоритм: Сортировка выбором (Selection Sort)
 * Тип: Сортировка (нестабильная)
 * 
 * Скорость: O(n^2) — всегда, без вариантов
 * Память: O(1)
 * 
 * Помнишь bubble_sort? Тот, который n^2 раз пробегал по всему массиву и менял всё подряд?
 * Вот это — его чуть более умный брат. Отличие в инварианте: у пузырька мы на каждом шаге
 * ставили arr[i] на место, гоняя его по всему массиву. А тут мы сначала ИЩЕМ минимум в arr[i..n-1],
 * и только потом меняем его с arr[i]. Один обмен на итерацию вместо n. Сравнений столько же, но
 * обменов в разы меньше.
 * 
 * Всё. Больше добавить нечего — остальное как в bubble_sort, только без тупняка с обменами.
 */

#include <iostream>
#include "algosiki.h"
using namespace std;

void selection_sort(Data* arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        size_t min = i;
        for (size_t j = i; j < n; j++) {
            if (arr[j].payload < arr[min].payload) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

int main() {

    /// Стандартный ввод

    size_t n;
    cin >> n;

    Data* data = new Data[n];

    for (size_t i = 0; i < n; i++) {
        int32_t key, val;
        cin >> key >> val;
        data[i] = { key, val };
    }

    /// Стандартный ввод

    // Выводим исходный массив
    print_array(data, n, fn_print_data);
    cout << endl;

    // Вызываем сортровку
    selection_sort(data, n);
    
    // Выводим отсортированный массив
    print_array(data, n, fn_print_data);

    return 0;
}