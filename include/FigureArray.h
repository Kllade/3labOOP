#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include <vector>
#include <memory>

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;

public:
    // Конструкторы
    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    
    // Деструктор
    ~FigureArray() = default;
    
    // Операторы присваивания
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
    
    // Основные методы
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(size_t index);
    size_t size() const;
    Figure* getFigure(size_t index) const;
    
    // Функции для работы с фигурами
    double getTotalArea() const;
    void printAllFigures() const;
    void printCenters() const;
    void printAreas() const;
    
    // Операторы доступа
    Figure* operator[](size_t index) const;
    
    // Итераторы
    auto begin() { return figures.begin(); }
    auto end() { return figures.end(); }
    auto begin() const { return figures.begin(); }
    auto end() const { return figures.end(); }
};

#endif // FIGUREARRAY_H
