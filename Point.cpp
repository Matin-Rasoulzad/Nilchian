#include "Point.h"
#include <cmath>

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

Point Point::operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
}

Point &Point::operator/=(int divisor) {
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return *this;
    }
    x /= divisor;
    y /= divisor;
    return *this;
}

Point &Point::operator=(const Point &other) {
    if (this == &other)
        return *this;
    x = other.x;
    y = other.y;
    return *this;
}

bool Point::operator>=(const Point &other) const {
    return (sqrt(x * x + y * y) >= sqrt(other.x * other.x + other.y * other.y));
}

ostream &operator<<(ostream &os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

istream &operator>>(istream &is, Point &point) {
    cout << "Enter x: ";
    is >> point.x;
    cout << "Enter y: ";
    is >> point.y;
    return is;
}
