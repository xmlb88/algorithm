#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
    // ���ݶ����Ƿ���const������display����
    Screen &display(ostream &os) {
        do_display(os); return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os); return *this;
    }

    Screen &set(char);
    Screen &set(pos, pos, char);

    inline Screen &Screen::set(char c) {
        contents[cursor] = c;   // ���õ�ǰ�������λ�õ���ֵ
        return *this;   // ��this������Ϊ��ֵ����
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
    // ������ʾScreen������
    void do_display(ostream &os) const {
        os << contents;
    }
    
    mutable size_t access_ctr; // �ɱ����ݳ�Ա����ʹ��һ��const������Ҳ�ܱ��޸�
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
    ++access_ctr;   // ����һ������ֵ�����ڼ�¼��Ա���������õĴ���
    // �ó�Ա��Ҫ��ɵ���������
}