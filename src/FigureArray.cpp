#include "FigureArray.h"
#include <iostream>
#include <algorithm>

// Конструктор по умолчанию
FigureArray::FigureArray() : data(nullptr), _size(0), _capacity(0) {}

// Вспомогательная функция для изменения размера массива
void FigureArray::resize() {
    size_t newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
    auto newData = std::make_unique<std::unique_ptr<Figure>[]>(newCapacity);
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
    _capacity = newCapacity;
}

// Конструктор копирования
FigureArray::FigureArray(const FigureArray& other)
    : data(nullptr), _size(0), _capacity(0) {
    if (other._size > 0) {
        _capacity = other._capacity;
        data = std::make_unique<std::unique_ptr<Figure>[]>(_capacity);
        for (size_t i = 0; i < other._size; ++i) {
            data[i] = std::unique_ptr<Figure>(other.data[i]->clone());
        }
        _size = other._size;
    }
}

// Конструктор перемещения
FigureArray::FigureArray(FigureArray&& other) noexcept
    : data(std::move(other.data)), _size(other._size), _capacity(other._capacity) {
    other._size = 0;
    other._capacity = 0;
}

// Оператор присваивания копированием
FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        // Создаем новый массив
        auto newData = std::make_unique<std::unique_ptr<Figure>[]>(other._capacity);
        for (size_t i = 0; i < other._size; ++i) {
            newData[i] = std::unique_ptr<Figure>(other.data[i]->clone());
        }
        // Перемещаем новые данные
        data = std::move(newData);
        _size = other._size;
        _capacity = other._capacity;
    }
    return *this;
}

// Оператор присваивания перемещением
FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        _size = other._size;
        _capacity = other._capacity;
        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

// Добавление фигуры
void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    if (_size == _capacity) {
        resize();
    }
    data[_size++] = std::move(figure);
}

// Удаление фигуры по индексу
void FigureArray::removeFigure(size_t index) {
    if (index < _size) {
        // Сдвигаем все элементы после удаленного влево
        for (size_t i = index; i < _size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        data[_size - 1].reset(); // Очищаем последний элемент
        --_size;
    }
}

// Размер массива
size_t FigureArray::size() const {
    return _size;
}

// Получение фигуры по индексу
Figure* FigureArray::getFigure(size_t index) const {
    if (index < _size) {
        return data[index].get();
    }
    return nullptr;
}

// Общая площадь всех фигур
double FigureArray::getTotalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        total += data[i]->getArea();
    }
    return total;
}

// Вывод всех фигур
void FigureArray::printAllFigures() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        std::cout << *data[i] << std::endl;
    }
}

// Вывод центров всех фигур
void FigureArray::printCenters() const {
    for (size_t i = 0; i < _size; ++i) {
        auto center = data[i]->getCenter();
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
    for (size_t i = 0; i < _size; ++i) {
        std::cout << "Площадь фигуры " << i + 1 << ": " << data[i]->getArea() << std::endl;
    }
}
