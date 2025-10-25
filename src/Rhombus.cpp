#include "Rhombus.h"
#include <cmath>

// Конструкторы
Rhombus::Rhombus(double s, double a, double x, double y) 
    : Figure("Ромб"), side(s), angle(a), x(x), y(y) {}

Rhombus::Rhombus(const Rhombus& other) 
    : Figure(other), side(other.side), angle(other.angle), x(other.x), y(other.y) {}

Rhombus::Rhombus(Rhombus&& other) noexcept 
    : Figure(std::move(other)), side(other.side), angle(other.angle), x(other.x), y(other.y) {}

// Операторы присваивания
Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        Figure::operator=(other);
        side = other.side;
        angle = other.angle;
        x = other.x;
        y = other.y;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        side = other.side;
        angle = other.angle;
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Оператор сравнения
bool Rhombus::operator==(const Rhombus& other) const {
    return Figure::operator==(other) && 
           std::abs(side - other.side) < 1e-9 &&
           std::abs(angle - other.angle) < 1e-9 &&
           std::abs(x - other.x) < 1e-9 &&
           std::abs(y - other.y) < 1e-9;
}

// Переопределение виртуальных методов
std::vector<double> Rhombus::getCenter() const {
    return {x, y};
}

double Rhombus::getArea() const {
    return side * side * sin(angle);
}

void Rhombus::printVertices(std::ostream& os) const {
    double halfSide = side / 2.0;
    
    // Вычисляем координаты вершин ромба
    double x1 = x;
    double y1 = y + halfSide;
    double x2 = x + halfSide * cos(angle);
    double y2 = y + halfSide * sin(angle);
    double x3 = x;
    double y3 = y - halfSide;
    double x4 = x - halfSide * cos(angle);
    double y4 = y - halfSide * sin(angle);
    
    os << "(" << x1 << ", " << y1 << ") ";
    os << "(" << x2 << ", " << y2 << ") ";
    os << "(" << x3 << ", " << y3 << ") ";
    os << "(" << x4 << ", " << y4 << ")";
}

void Rhombus::readFromStream(std::istream& is) {
    is >> side >> angle >> x >> y;
}

Figure* Rhombus::clone() const {
    return new Rhombus(*this);
}
