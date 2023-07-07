#include "Snake.h"

Snake::Snake() {
    //初始化贪吃蛇刚开始的状态
    Point point(1, 1);
    body.push_back(point);
    point.setY(2);
    body.push_back(point);
    direction = RIGHT;
}

std::list<Point> Snake::getBody() {
    return body;
}

void Snake::move() {
    for (auto it = body.begin(); it != body.end(); ++it) {
        if (it == std::prev(body.end())) {
            //改变头部
            switch (direction) {
                case UP:
                    //向上移，X-1，Y不变
                    it->setX(it->getX() - 1);
                    break;
                case DOWN:
                    //向下移，X+1，Y不变
                    it->setX(it->getX() + 1);
                    break;
                case LEFT:
                    //向左移，Y-1，X不变
                    it->setY(it->getY() - 1);
                    break;
                case RIGHT:
                    //向右移，Y+1，X不变
                    it->setY(it->getY() + 1);
                    break;
            }
        } else {
            //不是头部的就依次变成前一个的x,y值
            const Point &nextPoint = *std::next(it);
            (*it).setX(nextPoint.getX());
            (*it).setY(nextPoint.getY());
        }
    }

}

void Snake::changeDirection(Direction dir) {
    //不能让贪吃蛇向相反的方向移动
    if ((direction == UP && dir == DOWN) ||
        (direction == DOWN && dir == UP) ||
        (direction == LEFT && dir == RIGHT) ||
        (direction == RIGHT && dir == LEFT) ||
        direction == dir/*方向相同，不用作出改变*/) {
        return;
    }
    direction = dir;
}

bool Snake::checkCollision(int width, int height) {
    //获取贪吃蛇头部的坐标
    const Point &headPoint = body.back();
    //贪吃蛇是否撞墙的判断逻辑
    if ((headPoint.getX() == 1 && direction == UP) ||
        (headPoint.getY() == 1 && direction == LEFT) ||
        (headPoint.getX() == height - 2 && direction == DOWN) ||
        (headPoint.getY() == width - 2 && direction == RIGHT)) {
        return true;
    }
    return false;
}


