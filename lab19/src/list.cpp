#include "list.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::copy;
using std::out_of_range;

// Розширення масиву
void List::resize() {
    size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Audience* newAudiences = new Audience[newCapacity];
    copy(audiences, audiences + size, newAudiences);
    delete[] audiences;
    audiences = newAudiences;
    capacity = newCapacity;
}

// Конструктор
List::List() : audiences(nullptr), size(0), capacity(0) {
    cout << "Конструктор List викликаний" << endl;
}

// Деструктор
List::~List() {
    delete[] audiences;
    cout << "Деструктор List викликаний" << endl;
}

// Конструктор копіювання
List::List(const List& other) : size(other.size), capacity(other.capacity) {
    audiences = new Audience[capacity];
    copy(other.audiences, other.audiences + size, audiences);
    cout << "Конструктор копіювання List викликаний" << endl;
}

// Оператор присвоєння
List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] audiences;
        size = other.size;
        capacity = other.capacity;
        audiences = new Audience[capacity];
        copy(other.audiences, other.audiences + size, audiences);
        cout << "Оператор присвоєння List викликаний" << endl;
    }
    return *this;
}

// Додавання аудиторії
void List::addAudience(const Audience& audience, size_t pos) {
    if (size >= capacity) {
        resize();
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
    if (index >= size) throw out_of_range("Індекс поза межами");
    return audiences[index];
}

// Перевантаження оператора індексування
Audience& List::operator[](size_t index) {
    if (index >= size) throw out_of_range("Індекс поза межами");
    return audiences[index];
}

const Audience& List::operator[](size_t index) const {
    if (index >= size) throw out_of_range("Індекс поза межами");
    return audiences[index];
}

// Виведення аудиторій на екран
void List::print() const {
    for (size_t i = 0; i < size; ++i) {
        cout << audiences[i].toString() << endl;
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

// Запис у файл
void List::writeToFile(const string& fileName) const {
    ofstream file(fileName);
    if (!file) {
        cerr << "Помилка відкриття файлу для запису" << endl;
        return;
    }
    file << *this;
    file.close();
}

// Читання з файлу
void List::readFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання" << endl;
        return;
    }
    file >> *this;
    file.close();
}

// Перевантаження оператора виведення
ostream& operator<<(ostream& os, const List& list) {
    for (size_t i = 0; i < list.size; ++i) {
        os << list.audiences[i].toString() << endl;
    }
    return os;
}

// Перевантаження оператора введення
istream& operator>>(istream& is, List& list) {
    string line;
    while (getline(is, line)) {
        Audience audience;
        audience.fromString(line);
        list.addAudience(audience);
    }
    return is;
}
