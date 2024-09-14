#include "entity.h"
#include <sstream>

using std::stringstream;
using std::cout;
using std::endl;

// Конструктор за замовчуванням
Audience::Audience() : id(0), capacity(0) {
    cout << "Конструктор за замовчуванням викликаний" << endl;
}

// Конструктор з параметрами
Audience::Audience(int id, int capacity) : id(id), capacity(capacity) {
    cout << "Конструктор з параметрами викликаний: id = " << id << ", capacity = " << capacity << endl;
}

// Конструктор копіювання
Audience::Audience(const Audience& other) : id(other.id), capacity(other.capacity) {
    cout << "Конструктор копіювання викликаний: id = " << id << ", capacity = " << capacity << endl;
}

// Деструктор
Audience::~Audience() {
    cout << "Деструктор викликаний: id = " << id << ", capacity = " << capacity << endl;
}

// Оператор присвоєння
Audience& Audience::operator=(const Audience& other) {
    if (this != &other) {
        id = other.id;
        capacity = other.capacity;
    }
    return *this;
}

// Оператор порівняння
bool Audience::operator==(const Audience& other) const {
    return id == other.id && capacity == other.capacity;
}

bool Audience::operator!=(const Audience& other) const {
    return !(*this == other);
}

// Оператори введення/виведення
ostream& operator<<(ostream& os, const Audience& audience) {
    os << "Audience ID: " << audience.id << ", Capacity: " << audience.capacity;
    return os;
}

istream& operator>>(istream& is, Audience& audience) {
    is >> audience.id >> audience.capacity;
    return is;
}

// Гетери
int Audience::getId() const {
    return id;
}

int Audience::getCapacity() const {
    return capacity;
}

// Сетери
void Audience::setId(int id) {
    this->id = id;
}

void Audience::setCapacity(int capacity) {
    this->capacity = capacity;
}

// Метод, що повертає рядок-інформацію про об'єкт
string Audience::toString() const {
    stringstream ss;
    ss << "Audience ID: " << id << ", Capacity: " << capacity;
    return ss.str();
}

// Метод, що приймає рядок з інформацією про об'єкт
void Audience::fromString(const string& data) {
    size_t idPos = data.find("ID: ");
    size_t capacityPos = data.find(", Capacity: ");
    
    if (idPos != string::npos && capacityPos != string::npos) {
        id = std::stoi(data.substr(idPos + 4, capacityPos - (idPos + 4)));
        capacity = std::stoi(data.substr(capacityPos + 12));
    }
}
