#include <conio.h>
#include <iostream>
#include "Game.h"


Game::Game(const int &WIDTH, const int &HEIGHT) : width(WIDTH),
                                                  height(HEIGHT) {
    gameZone = new std::vector<std::vector<char>>();
    //���������ʱ�򣬿�ʼ��ʼ����Ϸ����������λ��
    init();

}

void Game::init() {
    //��ʼ����Ϸ����
    for (int i = 0; i < height; ++i) {
        gameZone->push_back(std::vector<char>());
        gameZone->back().resize(width, ' ');
        //ǽ����'#'�ַ���ʾ
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 ||
                j == 0 || j == width - 1) {
                gameZone->at(i).at(j) = '#';
            }
        }
    }
    //��ʼ����һ��ʳ������λ��
    srand(time(nullptr));
    int randomX, randomY;
    do {
        randomX = rand() % height;
        randomY = rand() % width;
    } while ((randomX == 1 && randomY == 1) ||
             (randomX == 1 && randomY == 2) ||
             (randomX == 0 || randomX == height - 1 ||
              randomY == 0 || randomY == width - 1));//��֤��һ��ʳ�ﲻ��������̰���߸տ�ʼ��λ���Լ��߽�
    food.setPosition(Point(randomX, randomY));
}

bool Game::gaming() {
    if (isGameOver) {
        std::cout << "��Ϸ������" << std::endl;
        return false;
    }
    renderGame();
    processInput();
    updateGame();
    return true;
}

void Game::renderGame() {
    //����
    system("cls");
    const std::list<Point> &body = snake.getBody();
    //�����̰���ߵ�λ�ã�����ʾ�����ַ�������̰���ߵ�λ��
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = '+';
    }
    //��ӡ
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == food.getPosition().getX() && j == food.getPosition().getY()) {
                std::cout << '+';
                continue;
            }
            std::cout << (*gameZone)[i][j];
        }
        std::cout << std::endl;
    }
    //������Ϸ����
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = ' ';
    }
}

void Game::processInput() {
    char key = 0;
    if (_kbhit()) {
        key = char(_getch());
    }
    //����������ĸΪ��д����ת��Сд�������ж�
    if (key >= 'A' && key <= 'Z') key += 32;
    switch (key) {
        case 'w':
            //����
            snake.changeDirection(UP);
            break;
        case 's':
            //����
            snake.changeDirection(DOWN);
            break;
        case 'a':
            //����
            snake.changeDirection(LEFT);
            break;
        case 'd':
            //����
            snake.changeDirection(RIGHT);
            break;
        case 'q':
            //�˳���Ϸ
            isGameOver = true;
            break;
        default:
            //���������������߼�
            break;
    }
}

void Game::updateGame() {
    //ײǽ����Ϸ����
    if (snake.checkCollision(width, height)) {
        isGameOver = true;
        return;
    }
    //ûײǽ�͸���̰���ߵĳ��Ⱥ�λ��
    int state = snake.move(food, width, height);
    //ײ���Լ�����Ϸ����
    if (state) isGameOver = true;
}
