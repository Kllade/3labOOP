#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "FigureArray.h"
#include <memory>
#include <cmath>

// Тесты для класса Trapezoid
TEST(TrapezoidTest, Constructor) {
    Trapezoid t(2.0, 4.0, 3.0, 0.0, 0.0);
    EXPECT_EQ(t.getTopBase(), 2.0);
    EXPECT_EQ(t.getBottomBase(), 4.0);
    EXPECT_EQ(t.getHeight(), 3.0);
    EXPECT_EQ(t.getX(), 0.0);
    EXPECT_EQ(t.getY(), 0.0);
}

TEST(TrapezoidTest, Area) {
    Trapezoid t(2.0, 4.0, 3.0, 0.0, 0.0);
    double expectedArea = (2.0 + 4.0) * 3.0 / 2.0; // 9.0
    EXPECT_DOUBLE_EQ(t.getArea(), expectedArea);
}

TEST(TrapezoidTest, Center) {
    Trapezoid t(2.0, 4.0, 3.0, 1.0, 2.0);
    auto center = t.getCenter();
    EXPECT_EQ(center.size(), 2);
    EXPECT_DOUBLE_EQ(center[0], 1.0);
    EXPECT_DOUBLE_EQ(center[1], 2.0);
}

TEST(TrapezoidTest, CopyConstructor) {
    Trapezoid t1(2.0, 4.0, 3.0, 0.0, 0.0);
    Trapezoid t2(t1);
    EXPECT_EQ(t1, t2);
}

TEST(TrapezoidTest, AssignmentOperator) {
    Trapezoid t1(2.0, 4.0, 3.0, 0.0, 0.0);
    Trapezoid t2;
    t2 = t1;
    EXPECT_EQ(t1, t2);
}

TEST(TrapezoidTest, MoveConstructor) {
    Trapezoid t1(2.0, 4.0, 3.0, 0.0, 0.0);
    Trapezoid t2(std::move(t1));
    EXPECT_DOUBLE_EQ(t2.getArea(), 9.0);
}

TEST(TrapezoidTest, Comparison) {
    Trapezoid t1(2.0, 4.0, 3.0, 0.0, 0.0);
    Trapezoid t2(2.0, 4.0, 3.0, 0.0, 0.0);
    Trapezoid t3(3.0, 4.0, 3.0, 0.0, 0.0);
    
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(TrapezoidTest, DoubleConversion) {
    Trapezoid t(2.0, 4.0, 3.0, 0.0, 0.0);
    double area = static_cast<double>(t);
    EXPECT_DOUBLE_EQ(area, 9.0);
}

// Тесты для класса Rhombus
TEST(RhombusTest, Constructor) {
    Rhombus r(2.0, 1.57, 0.0, 0.0); // угол ~90 градусов
    EXPECT_EQ(r.getSide(), 2.0);
    EXPECT_EQ(r.getAngle(), 1.57);
    EXPECT_EQ(r.getX(), 0.0);
    EXPECT_EQ(r.getY(), 0.0);
}

TEST(RhombusTest, Area) {
    Rhombus r(2.0, 1.57, 0.0, 0.0); // угол ~90 градусов
    double expectedArea = 2.0 * 2.0 * sin(1.57);
    EXPECT_NEAR(r.getArea(), expectedArea, 1e-6);
}

TEST(RhombusTest, Center) {
    Rhombus r(2.0, 1.57, 1.0, 2.0);
    auto center = r.getCenter();
    EXPECT_EQ(center.size(), 2);
    EXPECT_DOUBLE_EQ(center[0], 1.0);
    EXPECT_DOUBLE_EQ(center[1], 2.0);
}

TEST(RhombusTest, CopyConstructor) {
    Rhombus r1(2.0, 1.57, 0.0, 0.0);
    Rhombus r2(r1);
    EXPECT_EQ(r1, r2);
}

TEST(RhombusTest, AssignmentOperator) {
    Rhombus r1(2.0, 1.57, 0.0, 0.0);
    Rhombus r2;
    r2 = r1;
    EXPECT_EQ(r1, r2);
}

TEST(RhombusTest, Comparison) {
    Rhombus r1(2.0, 1.57, 0.0, 0.0);
    Rhombus r2(2.0, 1.57, 0.0, 0.0);
    Rhombus r3(3.0, 1.57, 0.0, 0.0);
    
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// Тесты для класса Pentagon
TEST(PentagonTest, Constructor) {
    Pentagon p(2.0, 0.0, 0.0);
    EXPECT_EQ(p.getSide(), 2.0);
    EXPECT_EQ(p.getX(), 0.0);
    EXPECT_EQ(p.getY(), 0.0);
}

TEST(PentagonTest, Area) {
    Pentagon p(2.0, 0.0, 0.0);
    double expectedArea = (5.0 * 2.0 * 2.0) / (4.0 * tan(M_PI / 5.0));
    EXPECT_NEAR(p.getArea(), expectedArea, 1e-6);
}

TEST(PentagonTest, Center) {
    Pentagon p(2.0, 1.0, 2.0);
    auto center = p.getCenter();
    EXPECT_EQ(center.size(), 2);
    EXPECT_DOUBLE_EQ(center[0], 1.0);
    EXPECT_DOUBLE_EQ(center[1], 2.0);
}

TEST(PentagonTest, CopyConstructor) {
    Pentagon p1(2.0, 0.0, 0.0);
    Pentagon p2(p1);
    EXPECT_EQ(p1, p2);
}

TEST(PentagonTest, AssignmentOperator) {
    Pentagon p1(2.0, 0.0, 0.0);
    Pentagon p2;
    p2 = p1;
    EXPECT_EQ(p1, p2);
}

TEST(PentagonTest, Comparison) {
    Pentagon p1(2.0, 0.0, 0.0);
    Pentagon p2(2.0, 0.0, 0.0);
    Pentagon p3(3.0, 0.0, 0.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// Тесты для полиморфизма
TEST(PolymorphismTest, VirtualFunctions) {
    std::unique_ptr<Figure> f1 = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    std::unique_ptr<Figure> f2 = std::make_unique<Rhombus>(2.0, 1.57, 0.0, 0.0);
    std::unique_ptr<Figure> f3 = std::make_unique<Pentagon>(2.0, 0.0, 0.0);
    
    // Проверяем, что виртуальные функции работают правильно
    EXPECT_NEAR(f1->getArea(), 9.0, 1e-6);
    EXPECT_NEAR(f2->getArea(), 2.0 * 2.0 * sin(1.57), 1e-6);
    EXPECT_NEAR(f3->getArea(), (5.0 * 2.0 * 2.0) / (4.0 * tan(M_PI / 5.0)), 1e-6);
}

TEST(PolymorphismTest, Clone) {
    Trapezoid t(2.0, 4.0, 3.0, 0.0, 0.0);
    Rhombus r(2.0, 1.57, 0.0, 0.0);
    Pentagon p(2.0, 0.0, 0.0);
    
    std::unique_ptr<Figure> tClone(t.clone());
    std::unique_ptr<Figure> rClone(r.clone());
    std::unique_ptr<Figure> pClone(p.clone());
    
    EXPECT_NEAR(tClone->getArea(), t.getArea(), 1e-6);
    EXPECT_NEAR(rClone->getArea(), r.getArea(), 1e-6);
    EXPECT_NEAR(pClone->getArea(), p.getArea(), 1e-6);
}

// Тесты для FigureArray
TEST(FigureArrayTest, Constructor) {
    FigureArray array;
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, AddFigure) {
    FigureArray array;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    array.addFigure(std::move(trapezoid));
    EXPECT_EQ(array.size(), 1);
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray array;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    auto rhombus = std::make_unique<Rhombus>(2.0, 1.57, 0.0, 0.0);
    
    array.addFigure(std::move(trapezoid));
    array.addFigure(std::move(rhombus));
    
    EXPECT_EQ(array.size(), 2);
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 1);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    auto rhombus = std::make_unique<Rhombus>(2.0, 1.57, 0.0, 0.0);
    
    array.addFigure(std::move(trapezoid));
    array.addFigure(std::move(rhombus));
    
    double totalArea = array.getTotalArea();
    double expectedArea = 9.0 + 2.0 * 2.0 * sin(1.57);
    EXPECT_NEAR(totalArea, expectedArea, 1e-6);
}

TEST(FigureArrayTest, GetFigure) {
    FigureArray array;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    array.addFigure(std::move(trapezoid));
    
    Figure* fig = array.getFigure(0);
    EXPECT_NE(fig, nullptr);
    EXPECT_NEAR(fig->getArea(), 9.0, 1e-6);
}

TEST(FigureArrayTest, CopyConstructor) {
    FigureArray array1;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    array1.addFigure(std::move(trapezoid));
    
    FigureArray array2(array1);
    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_NEAR(array1.getTotalArea(), array2.getTotalArea(), 1e-6);
}

TEST(FigureArrayTest, AssignmentOperator) {
    FigureArray array1;
    auto trapezoid = std::make_unique<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    array1.addFigure(std::move(trapezoid));
    
    FigureArray array2;
    array2 = array1;
    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_NEAR(array1.getTotalArea(), array2.getTotalArea(), 1e-6);
}

// Тесты граничных случаев
TEST(EdgeCasesTest, ZeroArea) {
    // После добавления валидации, нулевые значения должны выбрасывать исключение
    EXPECT_THROW(Trapezoid(0.0, 0.0, 1.0, 0.0, 0.0), std::invalid_argument);
}

TEST(EdgeCasesTest, NegativeValues) {
    // Отрицательные основания/высота должны выбрасывать исключение
    EXPECT_THROW(Trapezoid(-2.0, 4.0, 3.0, 0.0, 0.0), std::invalid_argument);
    EXPECT_THROW(Trapezoid(2.0, -4.0, 3.0, 0.0, 0.0), std::invalid_argument);
    EXPECT_THROW(Trapezoid(2.0, 4.0, -3.0, 0.0, 0.0), std::invalid_argument);

    // Отрицательная сторона ромба
    EXPECT_THROW(Rhombus(-2.0, 1.57, 0.0, 0.0), std::invalid_argument);

    // Отрицательная сторона пятиугольника
    EXPECT_THROW(Pentagon(-2.0, 0.0, 0.0), std::invalid_argument);

    // Неверный угол ромба (должен быть в диапазоне (0, π))
    EXPECT_THROW(Rhombus(2.0, 0.0, 0.0, 0.0), std::invalid_argument);
    EXPECT_THROW(Rhombus(2.0, M_PI, 0.0, 0.0), std::invalid_argument);
    EXPECT_THROW(Rhombus(2.0, -1.57, 0.0, 0.0), std::invalid_argument);
}

TEST(EdgeCasesTest, NegativeCoordinates) {
    // Отрицательные координаты центра - это ОК
    Trapezoid t(2.0, 4.0, 3.0, -1.0, -2.0);
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center[0], -1.0);
    EXPECT_DOUBLE_EQ(center[1], -2.0);
}

TEST(EdgeCasesTest, LargeNumbers) {
    Trapezoid t(1000.0, 2000.0, 500.0, 0.0, 0.0);
    double expectedArea = (1000.0 + 2000.0) * 500.0 / 2.0;
    EXPECT_DOUBLE_EQ(t.getArea(), expectedArea);
}

// Тесты операторов ввода/вывода
TEST(IOTest, OutputOperator) {
    Trapezoid t(2.0, 4.0, 3.0, 0.0, 0.0);
    std::ostringstream oss;
    oss << t;
    std::string output = oss.str();

    EXPECT_TRUE(output.find("Трапеция") != std::string::npos);
    EXPECT_TRUE(output.find("9") != std::string::npos); // площадь
}

TEST(IOTest, InputOperator) {
    Trapezoid t;
    std::istringstream iss("2.0 4.0 3.0 0.0 0.0");
    iss >> t;
    
    EXPECT_DOUBLE_EQ(t.getTopBase(), 2.0);
    EXPECT_DOUBLE_EQ(t.getBottomBase(), 4.0);
    EXPECT_DOUBLE_EQ(t.getHeight(), 3.0);
    EXPECT_DOUBLE_EQ(t.getX(), 0.0);
    EXPECT_DOUBLE_EQ(t.getY(), 0.0);
}
