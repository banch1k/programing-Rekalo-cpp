#include "list.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

void testAssignmentOperator();
void testAddRemoveAudience();
void testComparisonOperator();
void testFileOperations();
void testIndexingOperator();
void testInputOutputOperators();

// Тест оператора присвоєння
void testAssignmentOperator() {
    cout << "Тест оператора присвоєння:" << endl;

    List list1;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list1.addAudience(a1);
    list1.addAudience(a2);

    List list2;
    list2 = list1;

    cout << "List 1:" << endl;
    cout << list1;
    cout << "List 2:" << endl;
    cout << list2;
    cout << endl;
}

// Тест додавання та видалення аудиторій
void testAddRemoveAudience() {
    cout << "Тест додавання та видалення аудиторій:" << endl;

    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);

    list.addAudience(a1);
    list.addAudience(a2);

    cout << "Аудиторії:" << endl;
    cout << list;

    list.removeAudience(1);

    cout << "Після видалення аудиторії з індексом 1:" << endl;
    cout << list;
    cout << endl;
}

// Тест оператора порівняння
void testComparisonOperator() {
    cout << "Тест оператора порівняння:" << endl;

    Audience a1(1, 100);
    Audience a2(2, 200);
    Audience a3(1, 100);

    if (a1 == a3) {
        cout << "Аудиторії a1 і a3 рівні" << endl;
    } else {
        cout << "Аудиторії a1 і a3 не рівні" << endl;
    }

    if (a1 != a2) {
        cout << "Аудиторії a1 і a2 не рівні" << endl;
    } else {
        cout << "Аудиторії a1 і a2 рівні" << endl;
    }
    cout << endl;
}

// Тест операцій з файлами
void testFileOperations() {
    cout << "Тест операцій з файлами:" << endl;

    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);

    string fileName = "test_audiences.txt";

    // Запис у файл
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису" << endl;
        return;
    }
    outFile << list;
    outFile.close();
    cout << "Дані записані у файл: " << fileName << endl;

    // Читання з файлу
    List newList;
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання" << endl;
        return;
    }
    inFile >> newList;
    inFile.close();

    cout << "Дані прочитані з файлу:" << endl;
    cout << newList;
    cout << endl;
}

// Тест оператора індексування
void testIndexingOperator() {
    cout << "Тест оператора індексування:" << endl;

    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);

    cout << "Аудиторія з індексом 0:" << endl;
    cout << list[0] << endl;

    cout << "Аудиторія з індексом 1:" << endl;
    cout << list[1] << endl;

    try {
        cout << "Спроба доступу до аудиторії з індексом 2:" << endl;
        cout << list[2] << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
    cout << endl;
}

// Тест операторів введення/виведення
void testInputOutputOperators() {
    cout << "Тест операторів введення/виведення:" << endl;

    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);

    cout << "Виведення списку:" << endl;
    cout << list;

// Тест оператора введення
    stringstream ss;
    ss << list;
    List newList;
    ss >> newList;

    cout << "Список після оператора введення:" << endl;
    cout << newList;
    cout << endl;
}

int main() {
    testAssignmentOperator();
    testAddRemoveAudience();
    testComparisonOperator();
    testFileOperations();
    testIndexingOperator();
    testInputOutputOperators();
    cout << "Всі тести пройдено!" << endl;
    return 0;
}
