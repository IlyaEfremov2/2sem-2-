#include "point.h"
#include <stdexcept>

/**
* @brief Конструктор точки
* @param x Координата X
* @param y Координата Y
*/

Point::Point(double x, double y) : x(x), y(y) {
    validate(max_coord);
}

/**
* @brief Получение координаты X
* @return Значение координаты X
*/

double Point::getX() const { return x; }

/**
* @brief Получение координаты Y
* @return Значение координаты Y
*/

double Point::getY() const { return y; }

/**
* @brief Установка новой координаты X
* @param newX Новое значение координаты X
*/

void Point::setX(double newX) {
    x = newX;
    validate(max_coord);
}

/**
* @brief Установка новой координаты Y
* @param newY Новое значение координаты Y
*/

void Point::setY(double newY) {
    y = newY;
    validate(max_coord);
}

/**
* @brief Установка максимального значения координат
* @param max Максимальное допустимое значение координат
*/

void Point::setMaxCoord(double max) {
    double max_coord = max;
}

/**
* @brief Проверка координат точки
* @param max_coord Максимальное допустимое значение координат
*/

void Point::validate(double max_coord) const {
    if (x < 0 || y < 0 || x > max_сoord || y > max_сoord) {
        throw std::out_of_range("Координаты выходят за допустимые границы");
    }
}

/**
* @brief Оператор сравнения точек
* @param lhs Первая точка для сравнения
* @param rhs Вторая точка для сравнения
* @return true если точки равны, false в противном случае
*/

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}


bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
