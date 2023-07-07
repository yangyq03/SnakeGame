#ifndef SNAKEGAME_POINT_H
#define SNAKEGAME_POINT_H

class Point {
public:

    Point(int x, int y) {};

    int getX() const;

    int getY() const;

private:

    int x;
    int y;

};

#endif //SNAKEGAME_POINT_H
