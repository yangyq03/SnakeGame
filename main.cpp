#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"

//窗口的高度
int height;
//窗口的宽度
int width;
//游戏刷新时间（ms）
const int delayTime = 1000;

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
    std::cout << "分别输入游戏区域的宽和高以开始游戏：（不应太小，而且必须大于0）" << std::endl;
    //处理用户输入的宽高是否合理
    do {
        std::cin >> width >> height;
        if (width > 7 && height > 6)
            break;
        else
            std::cout << "设置失败！请重新输入： " << std::endl;
    } while (true);
    do {
        //开始初始化
        Game game(width, height);
        //游戏进行中
        while (game.gaming()) {
            Sleep(delayTime);
        }
        //游戏结束
    } while ((onPause()) != 'q');
    return 0;
}
