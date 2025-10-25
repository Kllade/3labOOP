#include "FigureArray.h"
#include <iostream>
#include <algorithm>

// Конструктор копирования
FigureArray::FigureArray(const FigureArray& other) {
    figures.reserve(other.figures.size());
    for (const auto& figure : other.figures) {
        figures.push_back(std::unique_ptr<Figure>(figure->clone()));
    }
}

// Конструктор перемещения
FigureArray::FigureArray(FigureArray&& other) noexcept 
    : figures(std::move(other.figures)) {}

// Оператор присваивания копированием
FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        figures.clear();
        figures.reserve(other.figures.size());
        for (const auto& figure : other.figures) {
            figures.push_back(std::unique_ptr<Figure>(figure->clone()));
        }
    }
    return *this;
}

// Оператор присваивания перемещением
FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        figures = std::move(other.figures);
    }
    return *this;
}

// Добавление фигуры
void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

// Удаление фигуры по индексу
void FigureArray::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

// Размер массива
size_t FigureArray::size() const {
    return figures.size();
}

// Получение фигуры по индексу
Figure* FigureArray::getFigure(size_t index) const {
    if (index < figures.size()) {
        return figures[index].get();
    }
    return nullptr;
}

// Общая площадь всех фигур
double FigureArray::getTotalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += figure->getArea();
    }
    return total;
}

// Вывод всех фигур
void FigureArray::printAllFigures() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        std::cout << *figures[i] << std::endl;
    }
}

// Вывод центров всех фигур
void FigureArray::printCenters() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->getCenter();
        std::cout << "Центр фигуры " << i + 1 << ": (";
        for (size_t j = 0; j < center.size(); ++j) {
            if (j > 0) std::cout << ", ";
            std::cout << center[j];
        }
        std::cout << ")" << std::endl;
    }
}

// Вывод площадей всех фигур
void FigureArray::printAreas() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Площадь фигуры " << i + 1 << ": " << figures[i]->getArea() << std::endl;
    }
}
