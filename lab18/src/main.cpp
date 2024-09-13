#include "list.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main() {
    List list;

    // Додавання аудиторій до списку
    Audience a1(1, 100);
    list.addAudience(a1);

    Audience a2(2, 200);
    list.addAudience(a2);

    // Виведення всіх аудиторій
    cout << "Всі аудиторії:" << endl;
    list.print();

    // Видалення аудиторії за індексом
    cout << "\nВидалення аудиторії з індексом 1:" << endl;
    list.removeAudience(1);
    list.print();

    // Додавання нової аудиторії
    Audience a3(3, 300);
    list.addAudience(a3);

    cout << "\nДодавання аудиторії:" << endl;
    list.print();

    // Отримання даних про аудиторію за індексом
    cout << "\nОтримання даних про аудиторію з індексом 1:" << endl;
    try {
        Audience& audience = list.getAudience(1);
        cout << audience.toString() << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    // Спроба отримати дані про аудиторію за неправильним індексом
    cout << "\nСпроба отримати дані про аудиторію з індексом 10:" << endl;
    try {
        Audience& audience = list.getAudience(10);
        cout << audience.toString() << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    // Пошук великих аудиторій
    size_t count;
    Audience* largeAudiences = list.findLargeAudiences(150, count);

    if (largeAudiences != nullptr) {
        cout << "\nВеликі аудиторії:\n";
        for (size_t i = 0; i < count; ++i) {
            cout << largeAudiences[i].toString() << endl;
        }
        delete[] largeAudiences;
    } else {
        cout << "Великих аудиторій не знайдено\n";
    }

    string fileName = "audiences.txt";

    // Запис у файл
    list.writeToFile(fileName);
    cout << "\nДані записані у файл: " << fileName << endl;

    // Читання з файлу
    List newList;
    newList.readFromFile(fileName);
    cout << "\nДані прочитані з файлу:" << endl;
    newList.print();

    return 0;
}

