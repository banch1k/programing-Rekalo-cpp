#include <iostream>
#include "entity.h"
#include "list.h"

// Тест конструктора за замовчуванням
void testConstructor() {
    std::cout << "Тест: Конструктор за замовчуванням\n";
    List list;
    list.print();
}

// Тест додавання нових аудиторій
void testAddAudience() {
    std::cout << "\nТест: Додавання нових аудиторій\n";
    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);
    list.print();
}

// Тест видалення аудиторії
void testRemoveAudience() {
    std::cout << "\nТест: Видалення аудиторії\n";
    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);
    list.print();

    list.removeAudience(0);
    list.print(); 
}

// Тест конструктора копіювання
void testCopyConstructor() {
    std::cout << "\nТест: Конструктор копіювання\n";
    List list;
    Audience a1(1, 100);
    Audience a2(2, 200);
    list.addAudience(a1);
    list.addAudience(a2);
    
    List copiedList(list);
    copiedList.print();
}

// Тест оператора присвоєння
void testAssignmentOperator() {
    std::cout << "\nТест: Оператор присвоєння\n";
    List list1;
    List list2;
    
    Audience a1(1, 100);
    Audience a2(2, 200);
    
    list1.addAudience(a1);
    list1.addAudience(a2);
    
    list2 = list1;
    list2.print();
}

// Пошук великих аудиторій
void testFindLargeAudiences() {
    std::cout << "\nТест: Пошук великих аудиторій\n";
    List list;
    Audience a1(1, 50);
    Audience a2(2, 151);
    Audience a3(3, 300);
    
    list.addAudience(a1);
    list.addAudience(a2);
    list.addAudience(a3);
    
    size_t count = 0;
    Audience* largeAudiences = list.findLargeAudiences(150, count);
    if (largeAudiences != nullptr && count > 0) {
        std::cout << "Великі аудиторії:\n";
        for (size_t i = 0; i < count; ++i) {
            largeAudiences[i].print();
        }
    } else {
        std::cout << "Великих аудиторій не знайдено\n";
    }
}

int main() {
    testConstructor();
    testAddAudience();
    testRemoveAudience();
    testCopyConstructor();
    testAssignmentOperator();
    testFindLargeAudiences();
    
    return 0;
}
