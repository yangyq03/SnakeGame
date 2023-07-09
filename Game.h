#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <vector>
#include "Snake.h"
#include "Food.h"

class Game {

public:

    Game(const int &width, const int &height);

    //��ʼ��
    void init();

    //��Ϸ�С�
    bool gaming();

    //��Ⱦ��Ϸ����
    void renderGame();

    //�����û��ļ�������������ı�̰���ߵ��ƶ�����
    void processInput();

    //����̰���ߵĳ��ȡ�λ���Լ��ƶ����������
    void updateGame();

private:

    //���ڵĸ߶�
    int height = 0;

    //���ڵĿ��
    int width = 0;

    //�ö�λ����ģ��̰������Ϸ����Ϸ����
    std::vector<std::vector<char>> *gameZone;

    //̰����
    Snake snake;

    //ʳ��
    Food food;

    //��Ϸ�Ƿ������һ����־����
    bool isGameOver = false;

};


#endif //SNAKEGAME_GAME_H
