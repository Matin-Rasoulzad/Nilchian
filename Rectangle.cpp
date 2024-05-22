#include "Rectangle.h"

Rectangle::Rectangle(Point startPoint, int width, int height)
        : startPoint(startPoint), width(width), height(height) {}

Rectangle::Rectangle(const Rectangle &other)
        : startPoint(other.startPoint), width(other.width), height(other.height) {}

void Rectangle::setStartPoint(Point startPoint) {
    this->startPoint = startPoint;
}

void Rectangle::setWidth(int width) {
    this->width = width;
}

void Rectangle::setHeight(int height) {
    this->height = height;
}

Point Rectangle::getStartPoint() const {
    return startPoint;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

Rectangle &Rectangle::operator+=(const Rectangle &other) {
    if (startPoint.getX() == other.startPoint.getX() && startPoint.getY() == other.startPoint.getY()) {
        width = max(width, other.width);
        height = max(height, other.height);
    } else {
        cout << "Error: Rectangles do not have the same starting point!" << endl;
    }
    return *this;
}

Rectangle &Rectangle::operator-=(const Rectangle &other) {
    if (startPoint.getX() == other.startPoint.getX() && startPoint.getY() == other.startPoint.getY()) {
        width = min(width, other.width);
        height = min(height, other.height);
    } else {
        cout << "Error: Rectangles do not have the same starting point!" << endl;
    }
    return *this;
}

Rectangle Rectangle::operator/(const Rectangle &other) const {
    Point midPoint((startPoint.getX() + other.startPoint.getX()) / 2, (startPoint.getY() + other.startPoint.getY()) / 2);
    int newWidth = max(width, other.width);
    int newHeight = max(height, other.height);
    return Rectangle(midPoint, newWidth, newHeight);
}

bool Rectangle::collisionDetection(const Rectangle &other) const {
    int x1 = startPoint.getX();
    int y1 = startPoint.getY();
    int x2 = x1 + width;
    int y2 = y1 + height;

    int ox1 = other.startPoint.getX();
    int oy1 = other.startPoint.getY();
    int ox2 = ox1 + other.width;
    int oy2 = oy1 + other.height;

    return !(x2 < ox1 || ox2 < x1 || y2 < oy1 || oy2 < y1);
}

ostream &operator<<(ostream &os, const Rectangle &rect) {
    os << "Start Point: " << rect.startPoint << ", Width: " << rect.width << ", Height: " << rect.height;
    return os;
}

istream &operator>>(istream &is, Rectangle &rect) {
    is >> rect.startPoint;
    cout << "Enter width: ";
    is >> rect.width;
    cout << "Enter height: ";
    is >> rect.height;
    return is;
}
