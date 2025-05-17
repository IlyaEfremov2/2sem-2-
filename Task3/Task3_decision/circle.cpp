#include "circle.h"
#include <cmath>
#include <sstream>
#include <stdexcept>


void Circle::validate() const {
    if (radius == 0) {
        throw std::invalid_argument("Радиус должен быть положительным");
    }

    double x = center.getX();
    double y = center.getY();

    if (x < radius || y < radius ||
        (x + radius) > max_coord ||
        (y + radius) > max_coord) {
        throw std::out_of_range("Круг выходит за границы допустимой области");
    }
}

Point Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }

double Circle::getArea() const {
    return radius * radius;
}

Circle::Circle(const Point& center, double radius, double max_coord)
    : center(center), radius(radius), max_coord(max_coord) {
    validate();
}

Circle::Circle(double x, double y, double radius, double max_coord)
    : center(x, y), radius(radius), max_coord(max_coord) {
    validate();
}

double Circle::getPerimeter() const {
    return 2 *  3.14 * radius;
}

bool Circle::contains(const Point& point) const {
    int dx = static_cast<int>(point.getX()) - static_cast<int>(center.getX());
    int dy = static_cast<int>(point.getY()) - static_cast<int>(center.getY());
    return (dx * dx + dy * dy) <= static_cast<int>(radius * radius);
}

std::string Circle::toString() const {
    std::ostringstream oss;
    oss << "круг с центром в точке " << center << " и радиусом " << radius;
    return oss.str();
}

Circle Circle::readFromStream(double max_coord) {
    Point center;
    double radius;

    std::cout << "ввод круга (формат: (x,y) радиус): ";
    std::cin >> center >> radius;

    return Circle(center, radius);
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    Point center;
    unsigned int radius;

    if (is >> center >> radius) {
        circle = Circle(center, radius);
    }

    return is;
}