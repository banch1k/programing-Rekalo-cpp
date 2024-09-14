#include "list.h"
#include <iostream>
#include <stdexcept>
#include <fstream> 

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    List list;

    // Додавання аудиторій до списку
    Audience a1(1, 100);
    list.addAudience(a1);

    Audience a2(2, 200);
    list.addAudience(a2);

    // Виведення всіх аудиторій
    cout << "Всі аудиторії:" << endl;
    cout << list;

    // Видалення аудиторії за індексом
    cout << "\nВидалення аудиторії з індексом 1:" << endl;
    list.removeAudience(1);
    cout << list;

    // Додавання нової аудиторії
    Audience a3(3, 300);
    list.addAudience(a3);

    cout << "\nДодавання аудиторії:" << endl;
    cout << list;

    // Отримання даних про аудиторію за індексом
    cout << "\nОтримання даних про аудиторію з індексом 1:" << endl;
    try {
        Audience& audience = list[1];
        cout << audience << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    // Спроба отримати дані про аудиторію за неправильним індексом
    cout << "\nСпроба отримати дані про аудиторію з індексом 10:" << endl;
    try {
        Audience& audience = list[10];
        cout << audience << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    // Пошук великих аудиторій
    size_t count;
    Audience* largeAudiences = list.findLargeAudiences(150, count);

    if (largeAudiences != nullptr) {
        cout << "\nВеликі аудиторії:\n";
        for (size_t i = 0; i < count; ++i) {
            cout << largeAudiences[i] << endl;
        }
        delete[] largeAudiences;
    } else {
        cout << "Великих аудиторій не знайдено\n";
    }

    string fileName = "audiences.txt";

    // Запис у файл
    ofstream outFile(fileName);
    outFile << list;
    outFile.close();
    cout << "\nДані записані у файл: " << fileName << endl;

    // Читання з файлу
    List newList;
    ifstream inFile(fileName);
    inFile >> newList;
    inFile.close();
    cout << "\nДані прочитані з файлу:" << endl;
    cout << newList;

    return 0;
}

