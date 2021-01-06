#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
    friend class Window_mgr;

    // 类型别名
    typedef string::size_type pos;
    // using pos = string::size_type;

    // 根据对象是否是const重载display函数
    Screen &display(ostream &os) {
        do_display(os); return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os); return *this;
    }
    // Screen &display(std::ostream &os) 
    //               { do_display(os); return *this; }
    // const Screen &display(std::ostream &os) const
    //               { do_display(os); return *this; }

    Screen &set(char);
    Screen &set(pos, pos, char);

    // 可变数据成员函数
    void some_member() const;
    
    // 构造函数
    Screen() = default;
    // cursor被其类内初始值初始化为0
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
    contents(ht * wd, c) {}
    char get() const {return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    // 显示Screen内容
    void do_display(ostream &os) const {os << contents;}

    // 可变数据成员，即使在一个const对象内也能被修改
    mutable size_t access_ctr;

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
    ++access_ctr;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}