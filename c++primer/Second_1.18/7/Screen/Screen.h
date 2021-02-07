#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
#include <string>

class Screen;
class Window_mgr {
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    // 按照编号将指定的Screen置为空白
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
    // window_mgr的成员可以访问Screen类的私有部分
    // friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default; // 因为Screen有另外一个构造函数，本函数必须
    // cursor被其类内初始化为0
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}
    // 读取光标处的字符
    char get() const { return contents[cursor]; } // 隐式内联
    inline char get(pos ht, pos wd) const; // 显式内联
    Screen& move(pos r, pos c); // 能在之后被设为内联

    Screen& set(char);
    Screen& set(pos, pos, char);

    // 根据对象是否是const重载了display函数
    Screen& display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen& display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

    void some_member() const { ++access_ctr; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;

    // 负责显示Screen的内容
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

// 内联能在类内部或者外部显式声明，定义在内部的函数自动隐式inline
inline
Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    // s是一个引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif