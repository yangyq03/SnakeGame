#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Game.h"


Game::Game(const int &WIDTH, const int &HEIGHT) : width(WIDTH),
                                                  height(HEIGHT) {
    gameZone = new std::vector<std::vector<char>>();
    //创建Game对象的时候，就开始初始化游戏区域和事物的位置
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
    //初始化第一个食物的随机位置
    srand(time(nullptr));
    int randomX, randomY;
    do {
        randomX = rand() % height;
        randomY = rand() % width;
        //保证食物不会生成在贪吃蛇刚开始的位置以及边界的位置
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
    //清屏
    system("cls");
    const std::list<Point> &body = snake.getBody();
    //如果是贪吃蛇的位置，则替换成'*'字符
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = '*';
    }
    //打印
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //食物的位置，也用'*'字符表示
            if (i == food.getPosition().getX() && j == food.getPosition().getY()) {
                std::cout << '*';
                continue;
            }
            std::cout << (*gameZone)[i][j];
        }
        std::cout << std::endl;
    }
    //下面两行用于隐藏光标
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    //用贪吃蛇的身体长度-1代表得分
    std::cout << "得分：" << body.size() - 1 << std::endl;
    //重置游戏区域
    for (const auto &item: body) {
        (*gameZone)[item.getX()][item.getY()] = ' ';
    }
}

void Game::processInput() {
    int key = 0;
    if (_kbhit()) key = _getch();
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
        default:
            //其他按键不做处理
            break;
    }
}

void Game::updateGame() {
    //撞墙，游戏结束
    if (snake.checkCollision(width, height)) {
        std::cout << "撞到墙了，游戏结束" << std::endl;
        isGameOver = true;
        return;
    }
    //没撞墙就更新贪吃蛇的长度和位置
    int state = snake.move(food, width, height);
    //撞到自己，游戏结束
    if (state) {
        std::cout << "你撞死了你自己，游戏结束" << std::endl;
        isGameOver = true;
    }
}
