#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0);
    Point(const Point &other);

    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    Point operator+(const Point &other) const;
    Point operator-(const Point &other) const;
    Point &operator/=(int divisor);
    Point &operator=(const Point &other);
    bool operator>=(const Point &other) const;

    friend ostream &operator<<(ostream &os, const Point &point);
    friend istream &operator>>(istream &is, Point &point);
};

#endif // POINT_H
