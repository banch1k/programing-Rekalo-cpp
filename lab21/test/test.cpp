#include "list.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

using std::cout;
using std::stringstream;

void testList() {
    List<int> intList;

    assert(intList.getSize() == 0 && "Початковий розмір має бути 0");

    intList.add(10);
    intList.add(18);
    intList.add(371);
    intList.add(3);

    cout << "Список: ";
    intList.display();

    assert(intList.indexOf(371) == 2 && "Індекс елемента 371 має бути 2");

    intList.sortarray();
    cout << "Список після сортування: ";
    intList.display();

    assert(intList.min() == 3 && "Мінімальний елемент має бути 3");

    intList.remove(2);
    cout << "Список після видалення елемента за індексом 2: ";
    intList.display();

    // Тестування введення та виведення
    stringstream ss;
    ss << intList;
    List<int> newList;
    ss >> newList;
    cout << "Нове виведення списку: ";
    newList.display();

    assert(newList.indexOf(3) == 0 && "Індекс елемента 3 має бути 0 після введення");
}

int main() {
    testList();
    cout << "Всі тести пройдено!" << endl;
    return 0;
}
