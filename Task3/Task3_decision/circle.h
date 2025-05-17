#pragma once
#include "shape.h"

class Circle : public Shape {
private:
    Point center;
    double radius;
    double max_coord;
    void validate() const;

public:
    Point getCenter() const;
    double getRadius() const;

    Circle(const Point& center, double radius, double max_coord);
    Circle(double x, double y, double radius, double max_coord);

    double getArea() const override;
    double getPerimeter() const override;
    bool contains(const Point& point) const override;
    std::string toString() const override;

    static Circle readFromStream(double maxCoord);
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};