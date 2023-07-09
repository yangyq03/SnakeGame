#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <list>
#include "Point.h"
#include "Food.h"

//̰���ߵ��ĸ��ƶ�����
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {

public:

    Snake();

    //����λ�õ㼯body
    std::list<Point> getBody() const;

    //̰���ߵ��ƶ�
    int move(Food &food, int width, int height);

    //�ı�̰�����ƶ��ķ���
    void changeDirection(Direction dir);

    //̰�����Ƿ�ײ��ǽ
    bool checkCollision(int weigh, int height);

private:

    //̰���ߵ����壬��list�б�ʵ��
    std::list<Point> body;

    //̰�����ƶ��ķ���
    Direction direction;

};

#endif //SNAKEGAME_SNAKE_H
