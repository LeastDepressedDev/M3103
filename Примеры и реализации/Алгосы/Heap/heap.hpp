/**
* Very inclear and "hard" code. Bad for algo sections. Tried to make code more readable, changed file extensions to more correct ones.
*
* TODO: Rewrite from scratch.
*
* Comment by LeastDepressedDev.
*/


/**
 * Минимальная двоичная куча (MinHeap).
 *
 * Куча — это полное бинарное дерево, в котором каждый родительский
 * узел не больше своих детей согласно заданному отношению порядка(компаратору).
 * Благодаря этому минимальный элемент всегда находится в корне.
 *
 * Куча хранится в динамическом массиве. Для элемента с индексом i в 0-индексации:
 * родитель:        (i - 1) / 2;
 * левый ребёнок:   2 * i + 1;
 * правый ребёнок:  2 * i + 2.
 *
 * Основные операции:
 * Top()    — получение минимума:   O(1);
 * Pop()    — удаление минимума:    O(log n) амортизированно;
 * Insert() — вставка элемента:     O(log n) амортизированно;
 * Построение из массива: O(n).
 * 
 * 
 * Копирование объектов MinHeap запрещено, поскольку класс самостоятельно
 * 
 * Компаратор less(a, b) возвращает true, если a < b
 */

#pragma once

#include <cstddef>
#include <cstdio>
#include <utility>
#include <stdexcept>


template <typename T>
using LessComparator = bool (*)(const T&, const T&);

void Raise(const char* const msg, int exit_code) {
    printf("Error raised: %s\nExit code: %d", msg, exit_code);
    exit(1);
}



template <typename T>
struct MinHeap  {
private:
    T* arr_;                    // Массив элементов кучи
    std::size_t capacity_;      // Вместимость массива
    std::size_t heap_size_;     // Количество элементов в куче
    LessComparator<T> less_;    // Компаратор

    // Просеивание вверх: восстанавливает свойство кучи после вставки
    void SiftUp(std::size_t i) {
        while (i > 0) {
            std::size_t j = (i - 1) / 2;
            if (!less_(arr_[i], arr_[j])) return;

            std::swap(arr_[i], arr_[j]);
            i = j;
        }
    }

    // Просеивание вниз: восстанавливает свойство кучи после удаления корня
    void SiftDown(std::size_t i) {
        while (true) {
            std::size_t l = 2 * i + 1;
            std::size_t r = 2 * i + 2;
            if (l >= heap_size_) return;

            std::size_t j = (r < heap_size_ && less_(arr_[r], arr_[l])) ? r : l;

            if (!less_(arr_[j], arr_[i])) return;
            std::swap(arr_[j], arr_[i]);
            i = j;
        }
    }

    // Перевыделяет память и переносит существующие элементы
    void Resize(std::size_t new_capacity) {
            capacity_ = new_capacity;
            T* new_arr = new T[capacity_];

            for (std::size_t i = 0; i < heap_size_; i++)
                new_arr[i] = arr_[i];

            delete[] arr_;
            arr_ = new_arr;
    }

    // Уменьшает массив вдвое, если занято не более четверти его ёмкости
    void TryDecreaseCapacity() {
        if (capacity_ > 1 && heap_size_ <= capacity_ / 4)
            Resize(capacity_ / 2);
    }

    // Увеличивает массив вдвое, если он заполнен
    void TryIncreaseCapacity() {
        if (heap_size_ >= capacity_)
            Resize(2 * capacity_);
    }

public:
    // Запрещаем копирование, чтобы избежать совместного владения массивом
    MinHeap(const MinHeap&) = delete;
    MinHeap& operator=(const MinHeap&) = delete;

    // Создаёт пустую кучу с начальной вместимостью 1
    MinHeap(LessComparator<T> less)
        : arr_(new T[1]), heap_size_(0), capacity_(1), less_(less) {

        if (less_ == nullptr)
            Raise("comparator cant't be nullptr", 1);
    }


    // Создаёт кучу из массива за O(n) с помощью просеивания вниз
    MinHeap(const T* arr, std::size_t size, LessComparator<T> less)
        : heap_size_(size), capacity_(1), less_(less) {

        if (less_ == nullptr)
            Raise("comparator cant't be nullptr", 1);

        while (capacity_ <= heap_size_)
            capacity_ *= 2;
        arr_ = new T[capacity_];
        for (std::size_t i = 0; i < heap_size_; i++)
            arr_[i] = arr[i];

        for (std::size_t i = heap_size_ / 2; i-- > 0;)
            SiftDown(i);
    }


    // Освобождает память массива
    ~MinHeap() {
        delete[] arr_;
    }


    // Возвращает true, если куча пуста
    bool IsEmpty() const { return heap_size_ == 0; }
    // Возвращает количество элементов в куче
    std::size_t GetHeapSize() const { return heap_size_; }


    // Возвращает минимальный элемент, не удаляя его
    // Бросает исключение, если куча пуста
    T Top() const {
        if (IsEmpty())
            throw std::out_of_range("Heap is empty");
        return arr_[0];
    }


    // Удаляет и возвращает минимальный элемент
    // Бросает исключение, если куча пуста
    T Pop() {
        if (IsEmpty())
            throw std::out_of_range("Heap is empty");

        T res = arr_[0];
        arr_[0] = arr_[--heap_size_];
        SiftDown(0);
        TryDecreaseCapacity();
        return res;
    }


    // Добавляет элемент и восстанавливает свойство кучи
    void Insert(T x) {
        TryIncreaseCapacity();
        arr_[heap_size_++] = x;
        SiftUp(heap_size_ - 1);
    }
};