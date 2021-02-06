#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen {
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

#endif