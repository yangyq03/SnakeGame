#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"

//���ڵĸ߶�
int height;
//���ڵĿ��
int width;
//��Ϸˢ��ʱ�䣨ms��
const int delayTime = 1000;

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
    std::cout << "�ֱ�������Ϸ����Ŀ�͸��Կ�ʼ��Ϸ������Ӧ̫С�����ұ������0��" << std::endl;
    //�����û�����Ŀ���Ƿ����
    do {
        std::cin >> width >> height;
        if (width > 7 && height > 6)
            break;
        else
            std::cout << "����ʧ�ܣ����������룺 " << std::endl;
    } while (true);
    do {
        //��ʼ��ʼ��
        Game game(width, height);
        //��Ϸ������
        while (game.gaming()) {
            Sleep(delayTime);
        }
        //��Ϸ����
    } while ((onPause()) != 'q');
    return 0;
}
