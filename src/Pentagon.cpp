#include "Pentagon.h"
#include <cmath>

// Конструкторы
Pentagon::Pentagon(double s, double x, double y) 
    : Figure("Пятиугольник"), side(s), x(x), y(y) {}

Pentagon::Pentagon(const Pentagon& other) 
    : Figure(other), side(other.side), x(other.x), y(other.y) {}

Pentagon::Pentagon(Pentagon&& other) noexcept 
    : Figure(std::move(other)), side(other.side), x(other.x), y(other.y) {}

// Операторы присваивания
Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        Figure::operator=(other);
        side = other.side;
        x = other.x;
        y = other.y;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        side = other.side;
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Оператор сравнения
bool Pentagon::operator==(const Pentagon& other) const {
    return Figure::operator==(other) && 
           std::abs(side - other.side) < 1e-9 &&
           std::abs(x - other.x) < 1e-9 &&
           std::abs(y - other.y) < 1e-9;
}

// Переопределение виртуальных методов
std::vector<double> Pentagon::getCenter() const {
    return {x, y};
}

double Pentagon::getArea() const {
    // Площадь правильного пятиугольника
    return (5.0 * side * side) / (4.0 * tan(M_PI / 5.0));
}

void Pentagon::printVertices(std::ostream& os) const {
    // Радиус описанной окружности
    double radius = side / (2.0 * sin(M_PI / 5.0));
    
    for (int i = 0; i < 5; ++i) {
        double angle = 2.0 * M_PI * i / 5.0 - M_PI / 2.0; // начинаем с верхней вершины
        double vertexX = x + radius * cos(angle);
        double vertexY = y + radius * sin(angle);
        
        if (i > 0) os << " ";
        os << "(" << vertexX << ", " << vertexY << ")";
    }
}

void Pentagon::readFromStream(std::istream& is) {
    is >> side >> x >> y;
}

Figure* Pentagon::clone() const {
    return new Pentagon(*this);
}
