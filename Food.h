#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include "Point.h"

class Food {

public:

    Food();

    void setPosition(const Point &pos);

    Point getPosition() const;

    //�����ﱻ����֮��������һ��ʳ���λ��
    void generateNewPosition(const std::list<Point> &body, int width, int height);

private:

    Point position;

};

#endif //SNAKEGAME_FOOD_H
