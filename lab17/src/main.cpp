#include "list.h"
#include <iostream>

int main() {
    List list;

    // Додавання аудиторій до списку
    Audience a1(1, 100);
    list.addAudience(a1);

    Audience a2(2, 200);
    list.addAudience(a2);

    // Виведення всіх аудиторій
    std::cout << "Всі аудиторії:" << std::endl;
    list.print();

    // Видалення аудиторії за індексом
    std::cout << "\nВидалення аудиторії з індексом 1:" << std::endl;
    list.removeAudience(1);
    list.print(); 

    // Додавання нової аудиторії
    Audience a3(3, 300);
    list.addAudience(a3);

    std::cout << "\nДодавання аудиторії:" << std::endl;
    list.print();

    // Отримання даних про аудиторію за індексом
    std::cout << "\nОтримання даних про аудиторію з індексом 1:" << std::endl;
    try {
        Audience& audience = list.getAudience(1);
        audience.print();
    } catch (const std::out_of_range& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    // Спроба отримати дані про аудиторію за неправильним індексом
    std::cout << "\nСпроба отримати дані про аудиторію з індексом 10:" << std::endl;
    try {
        Audience& audience = list.getAudience(10);
        audience.print();
    } catch (const std::out_of_range& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    // Пошук великих аудиторій
    size_t count;
    Audience* largeAudiences = list.findLargeAudiences(150, count);
    
    if (largeAudiences != nullptr) {
        std::cout << "\nВеликі аудиторії:\n";
        for (size_t i = 0; i < count; ++i) {
            largeAudiences[i].print();
        }
        delete[] largeAudiences;
    } else {
        std::cout << "Великих аудиторій не знайдено\n";
    }

    return 0;
}


