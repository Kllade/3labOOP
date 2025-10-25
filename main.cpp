#include <iostream>
#include <memory>
#include <limits>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "FigureArray.h"

void printMenu() {
    std::cout << "\n=== Система управления фигурами ===" << std::endl;
    std::cout << "1. Добавить трапецию" << std::endl;
    std::cout << "2. Добавить ромб" << std::endl;
    std::cout << "3. Добавить пятиугольник" << std::endl;
    std::cout << "4. Вывести все фигуры" << std::endl;
    std::cout << "5. Вывести центры" << std::endl;
    std::cout << "6. Вывести площади" << std::endl;
    std::cout << "7. Вывести общую площадь" << std::endl;
    std::cout << "8. Удалить фигуру по индексу" << std::endl;
    std::cout << "9. Читать фигуру из ввода" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите опцию: ";
}

std::unique_ptr<Figure> createFigure(int type) {
    try {
        switch (type) {
            // Трапеция
            case 1: {
                double top, bottom, height, x, y;
                std::cout << "Введите параметры трапеции (верхнее основание, нижнее основание, высота, x, y): ";
                if (!(std::cin >> top >> bottom >> height >> x >> y)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка: некорректный ввод данных!" << std::endl;
                    return nullptr;
                }
                std::cin.ignore();
                return std::make_unique<Trapezoid>(top, bottom, height, x, y);
            }
            // Ромб
            case 2: {
                double side, angle, x, y;
                std::cout << "Введите параметры ромба (сторона, угол, x, y): ";
                if (!(std::cin >> side >> angle >> x >> y)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка: некорректный ввод данных!" << std::endl;
                    return nullptr;
                }
                std::cin.ignore();
                return std::make_unique<Rhombus>(side, angle, x, y);
            }
            // 5-угольник
            case 3: {
                double side, x, y;
                std::cout << "Введите параметры пятиугольника (сторона, x, y): ";
                if (!(std::cin >> side >> x >> y)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка: некорректный ввод данных!" << std::endl;
                    return nullptr;
                }
                std::cin.ignore();
                return std::make_unique<Pentagon>(side, x, y);
            }
            default:
                return nullptr;
        }
    } catch (const std::exception& e) {
        std::cout << "Ошибка создания фигуры: " << e.what() << std::endl;
        return nullptr;
    }
}

int main() {
    FigureArray figures;
    int choice;
    
    std::cout << "Добро пожаловать в систему управления фигурами!" << std::endl;
    
    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число!" << std::endl;
            continue;
        }
        std::cin.ignore(); // Очищаем буфер 
        
        switch (choice) {
            case 1:
            case 2:
            case 3: {
                auto figure = createFigure(choice);
                if (figure) {
                    figures.addFigure(std::move(figure));
                    std::cout << "Фигура успешно добавлена!" << std::endl;
                } else {
                    std::cout << "Ошибка создания фигуры!" << std::endl;
                }
                break;
            }
            case 4: {
                if (figures.size() == 0) {
                    std::cout << "В массиве нет фигур!" << std::endl;
                } else {
                    figures.printAllFigures();
                }
                break;
            }
            case 5: {
                if (figures.size() == 0) {
                    std::cout << "В массиве нет фигур!" << std::endl;
                } else {
                    figures.printCenters();
                }
                break;
            }
            case 6: {
                if (figures.size() == 0) {
                    std::cout << "В массиве нет фигур!" << std::endl;
                } else {
                    figures.printAreas();
                }
                break;
            }
            case 7: {
                std::cout << "Общая площадь всех фигур: " << figures.getTotalArea() << std::endl;
                break;
            }
            case 8: {
                if (figures.size() == 0) {
                    std::cout << "В массиве нет фигур!" << std::endl;
                } else {
                    size_t index;
                    std::cout << "Введите индекс для удаления (0-" << figures.size() - 1 << "): ";
                    if (!(std::cin >> index)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Ошибка: введите число!" << std::endl;
                        break;
                    }
                    if (index < figures.size()) {
                        figures.removeFigure(index);
                        std::cout << "Фигура успешно удалена!" << std::endl;
                    } else {
                        std::cout << "Неверный индекс!" << std::endl;
                    }
                }
                break;
            }
            case 9: {
                std::cout << "Введите тип фигуры (1-Трапеция, 2-Ромб, 3-Пятиугольник): ";
                int type;
                if (!(std::cin >> type)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка: некорректный ввод!" << std::endl;
                    break;
                }

                std::unique_ptr<Figure> figure;
                try {
                    switch (type) {
                        case 1:
                            figure = std::make_unique<Trapezoid>();
                            break;
                        case 2:
                            figure = std::make_unique<Rhombus>();
                            break;
                        case 3:
                            figure = std::make_unique<Pentagon>();
                            break;
                        default:
                            std::cout << "Неверный тип фигуры!" << std::endl;
                            continue;
                    }

                    std::cout << "Введите данные фигуры: ";
                    std::cin >> *figure;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Ошибка: некорректный ввод данных!" << std::endl;
                        break;
                    }
                    figures.addFigure(std::move(figure));
                    std::cout << "Фигура успешно добавлена!" << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 0: {
                std::cout << "До свидания!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
        }
    }
    
    return 0;
}
