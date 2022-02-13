#pragma once
#include <iostream>

class Point {
public:
    float x;
    float y;
    Point() : x(0), y(0) {}
    Point(float x, float y) : x(x), y(y) {}

    friend std::ostream& operator << (std::ostream& os, const Point& p);
};

inline std::ostream& operator << (std::ostream& os, const Point& p) {
    os << p.x << ";" << p.y;
    return os;
}