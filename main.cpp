#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"

//窗口的高度
int height;
//窗口的宽度
int width;

//游戏结束后的下一步操作
int onPause() {
    std::cout << "按q退出游戏，按r重新开始" << std::endl;
    int key;
    do {
        key = _getch();
    } while (key != 'q' && key != 'r');
    return key;
}

int main() {
    std::cout << "分别输入游戏区域的宽和高以开始游戏：（宽度不应小于2）" << std::endl;
    std::cin >> width >> height;
    //贪吃蛇，启动！！
    do {
        Game *game = new Game(width, height);
        while (game->gaming()) {
            //刷新时间的毫秒值
            Sleep(500);
        }
        delete game;
    } while ((onPause()) != 'q');
    return 0;
}
