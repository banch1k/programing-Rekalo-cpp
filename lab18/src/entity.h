#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using std::string;

class Audience {
private:
    int id;
    int capacity;

public:
    // Конструктор за замовчуванням
    Audience();

    // Конструктор з параметрами
    Audience(int id, int capacity);

    // Конструктор копіювання
    Audience(const Audience& other);

    // Деструктор
    ~Audience();

    // Оператор присвоєння
    Audience& operator=(const Audience& other);

    // Гетери
    int getId() const;
    int getCapacity() const;

    // Сетери
    void setId(int id);
    void setCapacity(int capacity);

    // Метод, що повертає рядок-інформацію про об'єкт
    string toString() const;

    // Метод, що приймає рядок з інформацією про об'єкт
    void fromString(const string& data);
};

#endif // ENTITY_H
