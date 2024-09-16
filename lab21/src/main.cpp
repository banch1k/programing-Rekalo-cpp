#include "list.hpp"
#include <iostream>

using std::cout;

int main() {
    List<int> intList;

    intList.add(17);
    intList.add(2);
    intList.add(28);
    intList.add(3);
    intList.add(9);
    intList.add(25);
    intList.add(256);
    intList.add(1024);

    cout << "Список: ";
    intList.display();

    // Сортування масиву
    intList.sortarray();
    cout << "Список після сортування: ";
    intList.display();

    // Визначення індексу елемента масиву
    cout << "Індекс елемента 256: " << intList.indexOf(256) << std::endl;

    // Визначення значення мінімального елемента масиву
    cout << "Мінімальний елемент: " << intList.min() << std::endl;

    // Видалення елемента за індексом
    intList.remove(4);
    cout << "Список після видалення елемента за індексом 4: ";
    intList.display();

    return 0;
}
