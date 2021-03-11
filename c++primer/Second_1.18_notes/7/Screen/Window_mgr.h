#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <iostream>
#include <vector>
#include <string>
#include "Screen.h"

class Window_mgr {
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    // 按照编号将指定的Screen置为空白
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    // s是一个引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif