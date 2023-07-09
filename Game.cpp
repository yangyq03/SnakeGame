#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Game.h"


Game::Game(const int &WIDTH, const int &HEIGHT) : width(WIDTH),
                                                  height(HEIGHT) {
    gameZone = new std::vector<std::vector<char>>();
    //����Game�����ʱ�򣬾Ϳ�ʼ��ʼ����Ϸ����������λ��
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
        //��֤ʳ�ﲻ��������̰���߸տ�ʼ��λ���Լ��߽��λ��
    } while ((randomX == 1 && randomY == 1) ||
             (randomX == 1 && randomY == 2) ||
             (randomX == 0 || randomX == height - 1 ||
              randomY == 0 || randomY == width - 1));
    food.setPosition(Point(randomX, randomY));
}

bool Game::gaming() {
    if (isGameOver) return false;
    renderGame();
    processInput();
    updateGame();
    return true;
}

void Game::renderGame() {
    //����
    system("cls");
    const std::list<Point> &body = snake.getBody();
    //�����̰���ߵ�λ�ã����滻��'*'�ַ�
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = '*';
    }
    //��ӡ
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //ʳ���λ�ã�Ҳ��'*'�ַ���ʾ
            if (i == food.getPosition().getX() && j == food.getPosition().getY()) {
                std::cout << '*';
                continue;
            }
            std::cout << (*gameZone)[i][j];
        }
        std::cout << std::endl;
    }
    //���������������ع��
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    //��̰���ߵ����峤��-1����÷�
    std::cout << "�÷֣�" << body.size() - 1 << std::endl;
    //������Ϸ����
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = ' ';
    }
}

void Game::processInput() {
    int key = 0;
    if (_kbhit()) key = _getch();
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
        default:
            //����������������
            break;
    }
}

void Game::updateGame() {
    //ײǽ����Ϸ����
    if (snake.checkCollision(width, height)) {
        std::cout << "ײ��ǽ�ˣ���Ϸ����" << std::endl;
        isGameOver = true;
        return;
    }
    //ûײǽ�͸���̰���ߵĳ��Ⱥ�λ��
    int state = snake.move(food, width, height);
    //ײ���Լ�����Ϸ����
    if (state) {
        std::cout << "��ײ�������Լ�����Ϸ����" << std::endl;
        isGameOver = true;
    }
}
