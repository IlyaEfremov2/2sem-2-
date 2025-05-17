#include "../Task3/Task3_decision/circle.h"
#include "../Task3/Task3_decision/point.h"
#include "../Task3/Task3_decision/shape.h"
#include <iostream>
#include <locale>

/**
* @brief Получение точки с консольного ввода
* @return Объект Point, созданный из введенных координат
*/

Point getPoint(const std::string& message);

/**
* @brief Получение числового значения с консольного ввода
* @return Введенное пользователем число
*/
double getValue(const std::string& message);

/**
*@brief Точка входа в программу.
* @return 0 при успешном выполнении, при ошибке 1.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        double max_coord = 1920;

        Shape::setMaxCoord(max_coord);

        Point center = getPoint("Введите координаты центра (x y): ");
        double radius = getValue("Введите радиус: ");

        Shape* shape = new Circle(center, radius); 

        std::cout << *shape << std::endl;
        std::cout << "Площадь: " << shape->getArea() << std::endl;
        std::cout << "Периметр: " << shape->getPerimeter() << std::endl;

        Point testPoint = getPoint("Введите координаты точки для проверки (x y): ");
        std::cout << "Содержит ли точку " << testPoint << ": "
            << (shape->contains(testPoint) ? "ДА" : "НЕТ") << std::endl;

        delete shape;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/**
* @brief Реализация функции getPoint
*/

Point getPoint(const std::string& message) {
    double x, y;
    while (true) {
        std::cout << message;
        std::cin >> x >> y;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Ошибка ввода!\n";
        }
        else {
            break;
        }
    }
    return Point(x, y);
}

/**
* @brief Реализация функции getValue
*/

double getValue(const std::string& message) {
    double value;
    while (true) {
        std::cout << message;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Ошибка ввода!\n";
        }
        else {
            break;
        }
    }
    return value;
}