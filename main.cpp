#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"

//���ڵĸ߶�
int height;
//���ڵĿ��
int width;

//��Ϸ���������һ������
int onPause() {
    std::cout << "��q�˳���Ϸ����r���¿�ʼ" << std::endl;
    int key;
    do {
        key = _getch();
    } while (key != 'q' && key != 'r');
    return key;
}

int main() {
    std::cout << "�ֱ�������Ϸ����Ŀ�͸��Կ�ʼ��Ϸ������Ȳ�ӦС��2��" << std::endl;
    std::cin >> width >> height;
    //̰���ߣ���������
    do {
        Game *game = new Game(width, height);
        while (game->gaming()) {
            //ˢ��ʱ��ĺ���ֵ
            Sleep(500);
        }
        delete game;
    } while ((onPause()) != 'q');
    return 0;
}
