#include "Trapezoid.h"
#include <cmath>

// Конструкторы
Trapezoid::Trapezoid(double top, double bottom, double h, double x, double y) 
    : Figure("Трапеция"), topBase(top), bottomBase(bottom), height(h), x(x), y(y) {}

Trapezoid::Trapezoid(const Trapezoid& other) 
    : Figure(other), topBase(other.topBase), bottomBase(other.bottomBase), 
      height(other.height), x(other.x), y(other.y) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept 
    : Figure(std::move(other)), topBase(other.topBase), bottomBase(other.bottomBase), 
      height(other.height), x(other.x), y(other.y) {}

// Операторы присваивания
Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        Figure::operator=(other);
        topBase = other.topBase;
        bottomBase = other.bottomBase;
        height = other.height;
        x = other.x;
        y = other.y;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        topBase = other.topBase;
        bottomBase = other.bottomBase;
        height = other.height;
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Оператор сравнения
bool Trapezoid::operator==(const Trapezoid& other) const {
    return Figure::operator==(other) && 
           std::abs(topBase - other.topBase) < 1e-9 &&
           std::abs(bottomBase - other.bottomBase) < 1e-9 &&
           std::abs(height - other.height) < 1e-9 &&
           std::abs(x - other.x) < 1e-9 &&
           std::abs(y - other.y) < 1e-9;
}

// Переопределение виртуальных методов
std::vector<double> Trapezoid::getCenter() const {
    return {x, y};
}

double Trapezoid::getArea() const {
    return (topBase + bottomBase) * height / 2.0;
}

void Trapezoid::printVertices(std::ostream& os) const {
    double halfTop = topBase / 2.0;
    double halfBottom = bottomBase / 2.0;
    double halfHeight = height / 2.0;
    
    os << "(" << x - halfBottom << ", " << y - halfHeight << ") ";
    os << "(" << x + halfBottom << ", " << y - halfHeight << ") ";
    os << "(" << x + halfTop << ", " << y + halfHeight << ") ";
    os << "(" << x - halfTop << ", " << y + halfHeight << ")";
}

void Trapezoid::readFromStream(std::istream& is) {
    is >> topBase >> bottomBase >> height >> x >> y;
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}
