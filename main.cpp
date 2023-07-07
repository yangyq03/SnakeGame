#include <iostream>
#include <windows.h>
#include "Game.h"

//窗口的高度
int height = 20;
//窗口的宽度
int width = 30;

int main() {
    //贪吃蛇，启动！！
    Game game(width, height);
    while (game.gaming()) {
        //刷新时间的毫秒值
        Sleep(200);
    }
    std::cout << "游戏结束！" << std::endl;
    return 0;
}
