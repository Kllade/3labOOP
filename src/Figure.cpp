#include "Figure.h"

// Конструкторы
Figure::Figure(const std::string& figureName) : name(figureName) {}
Figure::Figure(const Figure& other) : name(other.name) {}
Figure::Figure(Figure&& other) noexcept : name(std::move(other.name)) {}

// Операторы присваивания
Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
    }
    return *this;
}

// Оператор сравнения
bool Figure::operator==(const Figure& other) const {
    return name == other.name;
}

// Оператор приведения к double (площадь)
Figure::operator double() const {
    return getArea();
}

// Операторы ввода/вывода
std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    os << "Фигура: " << figure.name << std::endl;
    os << "Центр: (";
    auto center = figure.getCenter();
    for (size_t i = 0; i < center.size(); ++i) {
        if (i > 0) os << ", ";
        os << center[i];
    }
    os << ")" << std::endl;
    os << "Площадь: " << figure.getArea() << std::endl;
    os << "Вершины: ";
    figure.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.readFromStream(is);
    return is;
}
