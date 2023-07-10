#include "Snake.h"

Snake::Snake() {
    //̰���߳�ʼ״̬
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
    //̰���߳Ե���ʳ�������+1��λ�ø��ݷ������
    if (headPoint->getX() == food.getPosition().getX() &&
        headPoint->getY() == food.getPosition().getY()) {
        switch (direction) {
            case UP:
                //�����ƣ�X-1��Y����
                body.emplace_back(headPoint->getX() - 1, headPoint->getY());
                break;
            case DOWN:
                //�����ƣ�X+1��Y����
                body.emplace_back(headPoint->getX() + 1, headPoint->getY());
                break;
            case LEFT:
                //�����ƣ�Y-1��X����
                body.emplace_back(headPoint->getX(), headPoint->getY() - 1);
                break;
            case RIGHT:
                //�����ƣ�Y+1��X����
                body.emplace_back(headPoint->getX(), headPoint->getY() + 1);
                break;
        }
        //������һ��ʳ��
        food.generateNewPosition(body, width, height);
    } else {
        for (auto it = body.begin(); it != body.end(); ++it) {
            if (it == headPoint) {
                //����ͷ��λ��
                switch (direction) {
                    case UP:
                        //�����ƣ�X-1��Y����
                        it->setX(it->getX() - 1);
                        break;
                    case DOWN:
                        //�����ƣ�X+1��Y����
                        it->setX(it->getX() + 1);
                        break;
                    case LEFT:
                        //�����ƣ�Y-1��X����
                        it->setY(it->getY() - 1);
                        break;
                    case RIGHT:
                        //�����ƣ�Y+1��X����
                        it->setY(it->getY() + 1);
                        break;
                }
            } else {
                //��ͷ����λ�����θ���Ϊǰһ����x,yֵ
                const Point &nextPoint = *std::next(it);
                it->setX(nextPoint.getX());
                it->setY(nextPoint.getY());
            }
            //���ײ���Լ�����Ϸ����
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
    //������̰�������෴�ķ����ƶ�
    if ((direction == UP && dir == DOWN) ||
        (direction == DOWN && dir == UP) ||
        (direction == LEFT && dir == RIGHT) ||
        (direction == RIGHT && dir == LEFT) ||
        direction == dir/*������ͬ�����������ı�*/) {
        return;
    }
    direction = dir;
}

bool Snake::checkCollision(int width, int height) {
    //��ȡ̰����ͷ��������
    const Point &headPoint = body.back();
    //̰�����Ƿ�ײǽ���ж��߼�
    if ((headPoint.getX() == 0) ||
        (headPoint.getY() == 0) ||
        (headPoint.getX() == height - 1) ||
        (headPoint.getY() == width - 1)) {
        return true;
    }
    return false;
}


