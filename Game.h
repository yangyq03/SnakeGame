#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <vector>
#include "Snake.h"
#include "Food.h"

class Game {

public:

    Game(const int &width, const int &height);

    //初始化
    void init();

    //游戏中…
    bool gaming();

    //渲染游戏界面
    void renderGame();

    //处理用户的键盘输入情况并改变贪吃蛇的移动方向
    void processInput();

    //更新贪吃蛇的位置和移动方向
    void updateGame();

private:

    //窗口的高度
    int height = 0;

    //窗口的宽度
    int width = 0;

    //用二位数组模拟贪吃蛇游戏的区域
    std::vector<std::vector<char>> *gameZone;

    //贪吃蛇
    Snake snake;

    //食物
    Food food;

    //游戏是否结束的一个标志变量
    bool isGameOver = false;

};


#endif //SNAKEGAME_GAME_H
