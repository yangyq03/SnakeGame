#include <list>
#include <ctime>
#include <cstdlib>
#include "Food.h"

Food::Food() {}

void Food::setPosition(const Point &pos) {
    this->position = pos;
}

Point Food::getPosition() const {
    return position;
}

void Food::generateNewPosition(const std::list<Point> &body, int width, int height) {
    srand(time(nullptr));
    int nextX, nextY;
    bool flag;
    do {
        flag = false;
        nextX = rand() % height;
        nextY = rand() % width;
        for (const auto &item: body) {
            if (nextX == item.getX() && nextY == item.getY()) {
                flag = true;
            }
        }
    } while (flag || (nextX == 0 || nextX == height - 1 ||
                      nextY == 0 || nextY == width - 1));//保证下一个食物的位置与贪吃蛇的位置不一样，而且也不能是边界
    this->position.setX(nextX);
    this->position.setY(nextY);
}
