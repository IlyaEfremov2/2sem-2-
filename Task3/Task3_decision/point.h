#pragma once
#include <iostream>

class Point {
private:
    double x;
    double y;
    double max_coord;

public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    void setX(double newX);
    void setY(double newY);
    static void setMaxCoord(double max);
    void validate() const;

    friend bool operator==(const Point& lhs, const Point& rhs);
    friend bool operator!=(const Point& lhs, const Point& rhs);
    friend Point operator+(const Point& point, double value);
    friend Point operator-(const Point& point, double value);
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
};
