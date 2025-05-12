#include "point.h"
#include <stdexcept>

Point::Point(double x, double y) : x(x), y(y) {
    validate();
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double newX) {
    x = newX;
    validate();
}

void Point::setY(double newY) {
    y = newY;
    validate();
}

void Point::setMaxCoord(double max) {
    double max_coord = max;
}

void Point::validate() const {
    if (x < max_coord || y < max_coord) {
        throw std::out_of_range("Координаты превышают максимально допустимое значение");
    }
}

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}

Point operator+(const Point& point, double value) {
    return Point(point.x + value, point.y + value);
}

Point operator-(const Point& point, double value) {
    if (value > point.x || value > point.y) {
        throw std::out_of_range("отрицательная координата");
    }
    return Point(point.x - value, point.y - value);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    char ch;
    double x, y;

    if (is >> ch && ch != '(') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> x)) return is;

    if (is >> ch && ch != ',') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> y)) return is;

    if (is >> ch && ch != ')') {
        is.setstate(std::ios::failbit);
        return is;
    }

    point.x = x;
    point.y = y;
    point.validate();

    return is;
}