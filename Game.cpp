#include <conio.h>
#include <iostream>
#include "Game.h"


Game::Game(const int &WIDTH, const int &HEIGHT) : width(WIDTH),
                                                  height(HEIGHT) {
    gameZone = new std::vector<std::vector<char>>();
    //创建对象的时候，开始初始化游戏区域
    init();
}

void Game::init() {
    //初始化游戏区域
    for (int i = 0; i < height; ++i) {
        gameZone->push_back(std::vector<char>());
        gameZone->back().resize(width, ' ');
        //墙壁用'#'字符表示
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 ||
                j == 0 || j == width - 1) {
                gameZone->at(i).at(j) = '#';
            }
        }
    }
}

bool Game::gaming() {
    if (isGameOver) {
        return false;
    }
    renderGame();
    processInput();
    updateGame();
    return true;
}

void Game::renderGame() {
    //清屏
    system("cls");
    const std::list<Point> &body = snake.getBody();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //如果是贪吃蛇的位置，则显示其他字符代表贪吃蛇的位置
            int flag = 1;
            for (const auto &item: body) {
                if (item.getX() == i && item.getY() == j) {
                    std::cout << '$';
                    flag = 0;
                }
            }
            if (flag) std::cout << (*gameZone)[i][j];
        }
        std::cout << std::endl;
    }
}

void Game::processInput() {
    char key = 0;
    if (_kbhit()) {
        key = char(_getch());
    }
    //如果键入的字母为大写，则转成小写，方便判断
    if (key >= 'A' && key <= 'Z') key += 32;
    switch (key) {
        case 'w':
            //向上
            snake.changeDirection(UP);
            break;
        case 's':
            //向下
            snake.changeDirection(DOWN);
            break;
        case 'a':
            //向左
            snake.changeDirection(LEFT);
            break;
        case 'd':
            //向右
            snake.changeDirection(RIGHT);
            break;
        case 'q':
            //退出游戏
            isGameOver = true;
            break;
        default:
            //处理其他按键的逻辑
            break;
    }
}

void Game::updateGame() {
    //如果贪吃蛇撞墙，游戏就结束
    if (snake.checkCollision(width, height)) {
        isGameOver = true;
        return;
    }
    //没撞墙就更新贪吃蛇的位置
    snake.move();
}
