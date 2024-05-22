#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Point.h"

using namespace std;

class Rectangle {
private:
    Point startPoint;
    int width, height;

public:
    Rectangle(Point startPoint = Point(), int width = 0, int height = 0);
    Rectangle(const Rectangle &other);

    void setStartPoint(Point startPoint);
    void setWidth(int width);
    void setHeight(int height);
    Point getStartPoint() const;
    int getWidth() const;
    int getHeight() const;

    Rectangle &operator+=(const Rectangle &other);
    Rectangle &operator-=(const Rectangle &other);
    Rectangle operator/(const Rectangle &other) const;

    bool collisionDetection(const Rectangle &other) const;

    friend ostream &operator<<(ostream &os, const Rectangle &rect);
    friend istream &operator>>(istream &is, Rectangle &rect);
};

#endif // RECTANGLE_H
