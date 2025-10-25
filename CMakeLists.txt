cmake_minimum_required(VERSION 3.10)
project(FigureManagement)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Google Test
find_package(GTest REQUIRED)

# Включение математической библиотеки
find_library(MATH_LIBRARY m)

# Добавление директории include
include_directories(include)

# Создание исполняемого файла
add_executable(lab3
    main.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/FigureArray.cpp
)

# Создание тестов
add_executable(tests 
    tests/test_figures.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/FigureArray.cpp
)

# Связывание с библиотеками
if(MATH_LIBRARY)
    target_link_libraries(lab3 ${MATH_LIBRARY})
    target_link_libraries(tests ${MATH_LIBRARY})
endif()

target_link_libraries(tests GTest::gtest_main)

# Настройки компилятора
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lab3 PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(lab3 PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
