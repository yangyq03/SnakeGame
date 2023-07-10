#include "Snake.h"

Snake::Snake() {
    //贪吃蛇初始状态
    Point point(1, 1);
    body.push_back(point);
    point.setY(2);
    body.push_back(point);
    direction = RIGHT;
}

std::list<Point> Snake::getBody() const {
    return body;
}

int Snake::move(Food &food, int width, int height) {
    const std::list<Point>::iterator &headPoint = std::prev(body.end());
    //贪吃蛇吃到了食物，自身长度+1，位置根据方向而定
    if (headPoint->getX() == food.getPosition().getX() &&
        headPoint->getY() == food.getPosition().getY()) {
        switch (direction) {
            case UP:
                //向上移，X-1，Y不变
                body.emplace_back(headPoint->getX() - 1, headPoint->getY());
                break;
            case DOWN:
                //向下移，X+1，Y不变
                body.emplace_back(headPoint->getX() + 1, headPoint->getY());
                break;
            case LEFT:
                //向左移，Y-1，X不变
                body.emplace_back(headPoint->getX(), headPoint->getY() - 1);
                break;
            case RIGHT:
                //向右移，Y+1，X不变
                body.emplace_back(headPoint->getX(), headPoint->getY() + 1);
                break;
        }
        //生成下一个食物
        food.generateNewPosition(body, width, height);
    } else {
        for (auto it = body.begin(); it != body.end(); ++it) {
            if (it == headPoint) {
                //更新头部位置
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
                //非头部的位置依次更新为前一个的x,y值
                const Point &nextPoint = *std::next(it);
                it->setX(nextPoint.getX());
                it->setY(nextPoint.getY());
            }
            //如果撞到自己，游戏结束
            if (it == headPoint) {
                for (auto i = body.begin(); i != std::prev(headPoint); ++i) {
                    if (it->getX() == i->getX() &&
                        it->getY() == i->getY()) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
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
    if ((headPoint.getX() == 0) ||
        (headPoint.getY() == 0) ||
        (headPoint.getX() == height - 1) ||
        (headPoint.getY() == width - 1)) {
        return true;
    }
    return false;
}


