#pragma once
#include "shape.h"

class Circle : public Shape {
private:
    Point center;
    double radius;

    void validateRadius() const;

public:
    Circle(const Point& center, double radius);
    Circle(double x, double y, double radius);

    Point getCenter() const;
    double getRadius() const;

    double getArea() const override;
    double getPerimeter() const override;
    bool contains(const Point& point) const override;
    std::string toString() const override;

    static Circle readFromStream();
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};