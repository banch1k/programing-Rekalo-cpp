#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

using std::ostream;
using std::istream;
using std::copy;
using std::cout;
using std::sort;
using std::out_of_range;
using std::endl;
using std::min_element;
using std::size_t;

template<typename T>
class List {
private:
    T* array;
    size_t size;
    size_t capacity;

    // Розширення масиву
    void resize() {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newArray = new T[newCapacity];
        copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    // Конструктор
    List() : array(nullptr), size(0), capacity(0) {}

    // Деструктор
    ~List() {
        delete[] array;
    }

    // Вивод масиву на екран
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

 	// Визначення індексу елемента масиву
 	size_t indexOf(const T& element) const {
    	for (size_t i = 0; i < size; ++i) {
        	if (array[i] == element) {
            	return i;
        	}
    	}
    return static_cast<size_t>(-1);
 	}

    // Сортування масиву
    void sortarray() {
        sort(array, array + size);
    }

    // Визначення значення мінімального елемента масиву
    T min() const {
        if (size == 0) {
            throw out_of_range("Масив порожній");
        }
        return *min_element(array, array + size);
    }

    // Додавання елемента у кінець масиву
    void add(const T& element) {
        if (size == capacity) {
            resize();
        }
        array[size++] = element;
    }

    // Видалення елемента за індексом
    void remove(size_t index) {
        if (index >= size) {
            throw out_of_range("Індекс поза межами");
        }
        for (size_t i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }

    // Оператор доступу за індексом
    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Індекс поза межами");
        }
        return array[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Індекс поза межами");
        }
        return array[index];
    }

    // Оператор виведення
    friend ostream& operator<<(ostream& os, const List& list) {
        for (size_t i = 0; i < list.size; ++i) {
            os << list.array[i] << " ";
        }
        return os;
    }

    // Оператор введення
    friend istream& operator>>(istream& is, List& list) {
        T element;
        while (is >> element) {
            list.add(element);
        }
        return is;
    }

    // Отримання розміру для тестування
 	size_t getSize() const {
    return size;
    }
};

#endif // LIST_HPP
