#include "list.h"
#include "entity.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

// Тестування запису та читання з файлу
void testFileOperations() {
    List list;

    Audience a1(1, 100);
    Audience a2(2, 200);

    list.addAudience(a1);
    list.addAudience(a2);

    list.writeToFile("test_output.txt");

    List newList;
    newList.readFromFile("test_output.txt");

    cout << "ID з індексом 0: " << newList.getAudience(0).getId() << endl;
    cout << "ID з індексом 1: " << newList.getAudience(1).getId() << endl;

    if (newList.getAudience(0).getId() == 1 &&
        newList.getAudience(1).getId() == 2) {
        cout << "Тест операцій з файлом пройдено!" << endl;
    } else {
        cout << "Тест операцій з файлом не пройдено!" << endl;
    }
}

// Тестування конструктора копіювання та оператора присвоєння
void testCopyAssignment() {
    List list1;
    Audience a1(1, 100);
    Audience a2(2, 200);

    list1.addAudience(a1);
    list1.addAudience(a2);

    List list2(list1);
    cout << "ID з індексом 0: " << list2.getAudience(0).getId() << endl;
    cout << "ID з індексом 1: " << list2.getAudience(1).getId() << endl;

    if (list2.getAudience(0).getId() == 1 &&
        list2.getAudience(1).getId() == 2) {
        cout << "Тест конструктора копіювання пройдено!" << endl;
    } else {
        cout << "Тест конструктора копіювання не пройдено!" << endl;
    }

    List list3;
    list3 = list1;
    cout << "ID з індексом 0: " << list3.getAudience(0).getId() << endl;
    cout << "ID з індексом 1: " << list3.getAudience(1).getId() << endl;

if (list3.getAudience(0).getId() == 1 &&
        list3.getAudience(1).getId() == 2) {
        cout << "Тест оператора присвоєння пройдено!" << endl;
    } else {
        cout << "Тест оператора присвоєння не пройдено!" << endl;
    }
}

// Тестування класу Audience
void testAudience() {

    // Тестування конструктора за замовчуванням
    Audience a;
    if (a.getId() == 0 && a.getCapacity() == 0) {
        cout << "Тест конструктора пройдено!" << endl;
    } else {
        cout << "Тест конструктора не пройдено!" << endl;
    }

    // Тестування конструктора з параметрами
    Audience a1(3, 300);
    if (a1.getId() == 3 && a1.getCapacity() == 300) {
        cout << "Тест конструктора з параметрами пройдено!" << endl;
    } else {
        cout << "Тест конструктора з параметрами не пройдено!" << endl;
    }

    // Тестування гетерів та сетерів
    a.setId(5);
    a.setCapacity(500);
    if (a.getId() == 5 && a.getCapacity() == 500) {
        cout << "Тест гетерів та сетерів пройдено!" << endl;
    } else {
        cout << "Тест гетерів та сетерів не пройдено!" << endl;
    }

    // Тестування методу, що повертає рядок-інформацію про об'єкт
    string expected = "Audience ID: 10, Capacity: 150";
    Audience a4(10, 150);
    if (a4.toString() == expected) {
        cout << "Тест методу, що повертає рядок-інформацію про об'єкт пройдено!" << endl;
    } else {
        cout << "Тест методу, що повертає рядок-інформацію про об'єкт не пройдено!" << endl;
    }

    // Тестування методу, що приймає рядок з інформацією про об'єкт
    Audience a5;
    string data = "Audience ID: 11, Capacity: 350";
    a5.fromString(data);
    if (a5.getId() == 11 && a5.getCapacity() == 350) {
        cout << "Тест методу, що приймає рядок з інформацією про об'єкт пройдено!" << endl;
    } else {
        cout << "Тест методу, що приймає рядок з інформацією про об'єкт не пройдено!" << endl;
    }
}

int main() {
    testAudience();
    testFileOperations();
    testCopyAssignment();
    cout << "Всі тести пройдено!" << endl;
    return 0;
}
