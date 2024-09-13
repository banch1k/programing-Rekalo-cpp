#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <stddef.h>

class List {
private:
    Audience* audiences;
    size_t size;
    size_t capacity;

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

    // Виведення аудиторій на екран
    void print() const;

    // Пошук великих аудиторій
    Audience* findLargeAudiences(int minCapacity, size_t& count) const;
};

#endif // LIST_H
