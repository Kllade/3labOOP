#include "Rhombus.h"
#include <cmath>
#include <stdexcept>

// Конструкторы
Rhombus::Rhombus(double s, double a, double x, double y)
    : Figure("Ромб"), side(s), angle(a), x(x), y(y) {
    if (s <= 0) {
        throw std::invalid_argument("Rhombus: сторона должна быть положительной");
    }
    if (a <= 0 || a >= M_PI) {
        throw std::invalid_argument("Rhombus: угол должен быть в диапазоне (0, π)");
    }
}

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
    // Диагонали ромба через сторону и угол:
    // d1 = 2 * side * sin(angle/2)
    // d2 = 2 * side * cos(angle/2)
    double halfD1 = side * sin(angle / 2.0);
    double halfD2 = side * cos(angle / 2.0);

    // Вершины ромба относительно центра (x, y)
    // Диагонали расположены вдоль осей координат
    double x1 = x;
    double y1 = y + halfD1;  // верхняя вершина
    double x2 = x + halfD2;
    double y2 = y;           // правая вершина
    double x3 = x;
    double y3 = y - halfD1;  // нижняя вершина
    double x4 = x - halfD2;
    double y4 = y;           // левая вершина

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
