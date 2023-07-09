#include "Point.h"

Point::Point() { x = 0, y = 0; }

Point::Point(int x, int y) : x(x), y(y) {}

void Point::setX(int m_x) {
    this->x = m_x;
}

void Point::setY(int m_y) {
    this->y = m_y;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}


