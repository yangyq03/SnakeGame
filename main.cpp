#include <iostream>
#include <windows.h>
#include "Game.h"

//窗口的高度
int height;
//窗口的宽度
int width;

int main() {
    std::cout << "分别输入游戏区域的宽和高以开始游戏：（宽度不应小于2）" << std::endl;
    std::cin >> width >> height;
    //贪吃蛇，启动！！
    Game game(width, height);
    while (game.gaming()) {
        //刷新时间的毫秒值
        Sleep(100);
    }
    system("pause");
    return 0;
}
