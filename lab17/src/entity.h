#ifndef ENTITY_H
#define ENTITY_H

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

    // Виведення аудиторій на екран
    void print() const;
};

#endif // ENTITY_H
