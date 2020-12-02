#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
using namespace std;

class Window_mgr {
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = vector<Screen>::size_type;
    // 按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    // s是一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    // 将那个选定的Screen重置为空白
    s.contents = string(s.height * s.width, ' ');
}