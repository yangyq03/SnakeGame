#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include "Point.h"

class Food {

public:

    Food();

    void setPosition(const Point &pos);

    Point getPosition() const;

    //当事物被吃了之后，生成下一个食物的位置
    void generateNewPosition(const std::list<Point> &body, int width, int height);

private:

    Point position;

};

#endif //SNAKEGAME_FOOD_H
