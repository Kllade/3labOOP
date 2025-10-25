#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

class Figure {
protected:
    std::string name;
    
public:
    // Конструкторы
    Figure(const std::string& figureName = "Figure");
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    
    // Виртуальный деструктор
    virtual ~Figure() = default;
    
    // Операторы присваивания
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;
    
    // Оператор сравнения
    virtual bool operator==(const Figure& other) const;
    
    // Виртуальные методы
    virtual std::vector<double> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readFromStream(std::istream& is) = 0;
    virtual Figure* clone() const = 0;
    
    // Оператор приведения к double (площадь)
    virtual operator double() const;
    
    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    
    // Геттеры
    const std::string& getName() const { return name; }
};

#endif // FIGURE_H
