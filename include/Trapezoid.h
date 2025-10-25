#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
private:
    double topBase;    // верхнее основание
    double bottomBase; // нижнее основание
    double height;     // высота
    double x, y;       // координаты центра

public:
    // Конструкторы
    Trapezoid(double top = 2.0, double bottom = 4.0, double h = 3.0, double x = 0.0, double y = 0.0);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    
    // Деструктор
    virtual ~Trapezoid() = default;
    
    // Операторы присваивания
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Trapezoid& other) const;
    
    // Переопределение виртуальных методов
    std::vector<double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    Figure* clone() const override;
    
    // Геттеры
    double getTopBase() const { return topBase; }
    double getBottomBase() const { return bottomBase; }
    double getHeight() const { return height; }
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Сеттеры
    void setTopBase(double top) { topBase = top; }
    void setBottomBase(double bottom) { bottomBase = bottom; }
    void setHeight(double h) { height = h; }
    void setPosition(double newX, double newY) { x = newX; y = newY; }
};

#endif // TRAPEZOID_H
