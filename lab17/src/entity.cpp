#include "entity.h"
#include <iostream>

// Конструктор за замовчуванням
Audience::Audience() : id(0), capacity(0) {
    std::cout << "Конструктор за замовчуванням викликаний" << std::endl;
}

// Конструктор з параметрами
Audience::Audience(int id, int capacity) : id(id), capacity(capacity) {
    std::cout << "Конструктор з параметрами викликаний: id = " << id << ", capacity = " << capacity << std::endl;
}

// Конструктор копіювання
Audience::Audience(const Audience& other) : id(other.id), capacity(other.capacity) {
    std::cout << "Конструктор копіювання викликаний: id = " << id << ", capacity = " << capacity << std::endl;
}

// Деструктор
Audience::~Audience() {
    std::cout << "Деструктор викликаний: id = " << id << ", capacity = " << capacity << std::endl;
}

// Оператор присвоєння
Audience& Audience::operator=(const Audience& other) {
    if (this != &other) {
        id = other.id;
        capacity = other.capacity;
        std::cout << "Оператор присвоєння викликаний: id = " << id << ", capacity = " << capacity << std::endl;
    }
    return *this;
}

// Гетери
int Audience::getId() const {
    return id;
}

int Audience::getCapacity() const {
    return capacity;
}

// Сетери
void Audience::setId(int id) {
    this->id = id;
}

void Audience::setCapacity(int capacity) {
    this->capacity = capacity;
}

// Виведення аудиторій на екран
void Audience::print() const {
    std::cout << "Audience ID: " << id << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

