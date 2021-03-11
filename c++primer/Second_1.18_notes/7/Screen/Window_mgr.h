#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <iostream>
#include <vector>
#include <string>
#include "Screen.h"

class Window_mgr {
public:
    // ������ÿ����Ļ�ı��
    using ScreenIndex = std::vector<Screen>::size_type;
    // ���ձ�Ž�ָ����Screen��Ϊ�հ�
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    // s��һ�����ã�ָ����������յ��Ǹ���Ļ
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif