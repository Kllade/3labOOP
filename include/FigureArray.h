#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include <memory>

class FigureArray {
private:
    std::unique_ptr<std::unique_ptr<Figure>[]> data;
    size_t _size;
    size_t _capacity;
    void resize();

public:
    // Конструкторы
    FigureArray();
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
};

#endif // FIGUREARRAY_H
