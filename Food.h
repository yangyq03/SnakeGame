#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include "Point.h"

class Food {

public:

    Food();

    explicit Food(Point point);

    //更新食物位置
    void generateNewPosition();

private:

    Point position;

};


#endif //SNAKEGAME_FOOD_H
