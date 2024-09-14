#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class List {
private:
    Audience* audiences;
    size_t size;
    size_t capacity;

    void resize();

public:
    // Конструктор
    List();

    // Деструктор
    ~List();

    // Конструктор копіювання
    List(const List& other);

    // Оператор присвоєння
    List& operator=(const List& other);

    // Додавання аудиторії
    void addAudience(const Audience& audience, size_t pos = 0);

    // Видалення аудиторії
    void removeAudience(size_t index);

    // Отримання аудиторії за індексом
    Audience& getAudience(size_t index);

    // Перевантаження оператора індексування
    Audience& operator[](size_t index);
    const Audience& operator[](size_t index) const;

    // Виведення аудиторій на екран
    void print() const;

    // Пошук великих аудиторій
    Audience* findLargeAudiences(int minCapacity, size_t& count) const;

    // Читання з файлу
    void readFromFile(const string& fileName);

    // Запис у файл
    void writeToFile(const string& fileName) const;

    // Перевантаження операторів введення/виведення
    friend ostream& operator<<(ostream& os, const List& list);
    friend istream& operator>>(istream& is, List& list);
};

#endif // LIST_H
