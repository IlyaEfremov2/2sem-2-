#include "shape.h"

void Shape::setMaxCoord(double max) {
    double max_coord = max;
    Point::setMaxCoord(max);
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    os << shape.toString();
    return os;
}