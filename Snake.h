#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <list>
#include "Point.h"

//贪吃蛇的四个移动方向
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {

public:

    Snake();

    //返回位置点集body
    std::list<Point> getBody();

    //贪吃蛇的移动
    void move();

    //改变贪吃蛇移动的方向
    void changeDirection(Direction dir);

    //贪吃蛇是否撞到墙
    bool checkCollision(int weigh, int height);

private:

    //贪吃蛇的身体，用list列表表示
    std::list<Point> body;

    //移动方向
    Direction direction;

};

#endif //SNAKEGAME_SNAKE_H
