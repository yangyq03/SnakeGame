#include <iostream>
#include <windows.h>
#include "Game.h"

//���ڵĸ߶�
int height;
//���ڵĿ��
int width;

int main() {
    std::cout << "�ֱ�������Ϸ����Ŀ�͸��Կ�ʼ��Ϸ������Ȳ�ӦС��2��" << std::endl;
    std::cin >> width >> height;
    //̰���ߣ���������
    Game game(width, height);
    while (game.gaming()) {
        //ˢ��ʱ��ĺ���ֵ
        Sleep(100);
    }
    system("pause");
    return 0;
}
