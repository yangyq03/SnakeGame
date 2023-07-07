#ifndef MYPROJECT_GAME_H
#define MYPROJECT_GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
public:

    Game() {
        //当创建Game对象时，就开始调用initGame函数初始化游戏
        initGame();
    }

    //初始化游戏
    void initGame();

    //处理用户的键盘输入情况以改变蛇的移动方向
    void processInput();

    //用户改变方向之后，更新游戏
    void updateGame();

    //渲染游戏界面
    void renderGame();

    //检查蛇是否碰撞到墙
    bool checkCollision();

private:

    int width = 100;//窗口的宽度
    int heigth = 100;//窗口的高度
    Snake snake;//蛇
    Food food;//食物
    bool isGameOver = false;//游戏是否结束

};


#endif //MYPROJECT_GAME_H
