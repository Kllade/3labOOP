#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
private:
    double side;       // длина стороны
    double x, y;       // координаты центра

public:
    // Конструкторы
    Pentagon(double s = 2.0, double x = 0.0, double y = 0.0);
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    
    // Деструктор
    virtual ~Pentagon() = default;
    
    // Операторы присваивания
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Pentagon& other) const;
    
    // Переопределение виртуальных методов
    std::vector<double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    Figure* clone() const override;
    
    // Геттеры
    double getSide() const { return side; }
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Сеттеры
    void setSide(double s) { side = s; }
    void setPosition(double newX, double newY) { x = newX; y = newY; }
};

#endif // PENTAGON_H
