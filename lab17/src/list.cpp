#include "list.h"
#include <algorithm> // для std::copy
#include <stdexcept>  // Для std::out_of_range
#include <iostream>   // Для std::cout

// Конструктор
List::List() : audiences(nullptr), size(0), capacity(0) {
    std::cout << "Конструктор List викликаний" << std::endl;
}

// Деструктор
List::~List() {
    delete[] audiences;
    std::cout << "Деструктор List викликаний" << std::endl;
}

// Конструктор копіювання
List::List(const List& other) : size(other.size), capacity(other.capacity) {
    audiences = new Audience[capacity];
    std::copy(other.audiences, other.audiences + size, audiences);
    std::cout << "Конструктор копіювання List викликаний" << std::endl;
}

// Оператор присвоєння
List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] audiences;
        size = other.size;
        capacity = other.capacity;
        audiences = new Audience[capacity];
        std::copy(other.audiences, other.audiences + size, audiences);
        std::cout << "Оператор присвоєння List викликаний" << std::endl;
    }
    return *this;
}

// Додавання аудиторії
void List::addAudience(const Audience& audience, size_t pos) {
    if (size >= capacity) {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Audience* newAudiences = new Audience[newCapacity];
        std::copy(audiences, audiences + size, newAudiences);
        delete[] audiences;
        audiences = newAudiences;
        capacity = newCapacity;
    }
    if (pos > size) pos = size;
    for (size_t i = size; i > pos; --i) {
        audiences[i] = audiences[i - 1];
    }
    audiences[pos] = audience;
    ++size;
}

// Видалення аудиторії
void List::removeAudience(size_t index) {
    if (index >= size) return;
    for (size_t i = index; i < size - 1; ++i) {
        audiences[i] = audiences[i + 1];
    }
    --size;
}

// Отримання аудиторії за індексом
Audience& List::getAudience(size_t index) {
    if (index >= size) throw std::out_of_range("Індекс поза межами");
    return audiences[index];
}

// Виведення аудиторій на екран
void List::print() const {
    for (size_t i = 0; i < size; ++i) {
        audiences[i].print();
    }
}

// Пошук великих аудиторій
Audience* List::findLargeAudiences(int minCapacity, size_t& count) const {
    count = 0;
    
    for (size_t i = 0; i < size; ++i) {
        if (audiences[i].getCapacity() >= minCapacity) {
            ++count;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    Audience* largeAudiences = new Audience[count];
    size_t index = 0;

    for (size_t i = 0; i < size; ++i) {
        if (audiences[i].getCapacity() >= minCapacity) {
            largeAudiences[index++] = audiences[i];
        }
    }

    return largeAudiences;
}
