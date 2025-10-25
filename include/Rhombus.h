#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
private:
    double side;       // длина стороны
    double angle;      // угол в радианах
    double x, y;       // координаты центра

public:
    // Конструкторы
    Rhombus(double s = 2.0, double a = 1.57, double x = 0.0, double y = 0.0); // угол по умолчанию 90 градусов
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    
    // Деструктор
    virtual ~Rhombus() = default;
    
    // Операторы присваивания
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Rhombus& other) const;
    
    // Переопределение виртуальных методов
    std::vector<double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& os) const override;

    // Чтение из потока: сторона угол(радианы) x y
    void readFromStream(std::istream& is) override;
    Figure* clone() const override;
    
    // Геттеры
    double getSide() const { return side; }
    double getAngle() const { return angle; }
    double getX() const { return x; }
    double getY() const { return y; }
};

#endif // RHOMBUS_H
