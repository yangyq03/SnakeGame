#ifndef SNAKEGAME_POINT_H
#define SNAKEGAME_POINT_H

class Point {

public:

    Point();

    Point(int x, int y);

    void setX(int m_x);

    void setY(int m_y);

    int getX() const;

    int getY() const;

private:

    int x;

    int y;

};

#endif //SNAKEGAME_POINT_H
