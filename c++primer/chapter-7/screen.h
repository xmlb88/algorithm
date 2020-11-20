#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
    // 根据对象是否是const重载了display函数
    Screen &display(ostream &os) {
        do_display(os); return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os); return *this;
    }

    Screen &set(char);
    Screen &set(pos, pos, char);

    inline Screen &Screen::set(char c) {
        contents[cursor] = c;   // 设置当前光标所在位置的新值
        return *this;   // 将this对象作为左值返回
    }
    inline Screen &Screen::set(pos r, pos col, char ch) {
        contents[r * width + col] = ch;
        return *this;
    }

    void some_member() const;
    // typedef string::size_type pos;
    using pos = string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
    contents(ht * wd, c) {}
    char get() const {return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    // 负责显示Screen的内容
    void do_display(ostream &os) const {
        os << contents;
    }
    
    mutable size_t access_ctr; // 可变数据成员，即使在一个const对象内也能被修改
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const {
    ++access_ctr;   // 保存一个计数值，用于记录成员函数被调用的次数
    // 该成员需要完成的其他工作
}