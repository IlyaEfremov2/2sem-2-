#pragma once
#include "point.h"
#include <string>

class Shape {
protected:
    double max_coord;

public:
    virtual ~Shape() = default;

    static void setMaxCoord(double max);

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual bool contains(const Point& point) const = 0;
    virtual std::string toString() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};