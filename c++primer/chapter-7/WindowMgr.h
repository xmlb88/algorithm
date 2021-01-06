#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
using namespace std;

class Window_mgr {
public:
    // ������ÿ����Ļ�ı��
    using ScreenIndex = vector<Screen>::size_type;
    // ���ձ�Ž�ָ����Screen����Ϊ�հ�
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    // s��һ��Screen�����ã�ָ����������յ��Ǹ���Ļ
    Screen &s = screens[i];
    // ���Ǹ�ѡ����Screen����Ϊ�հ�
    s.contents = string(s.height * s.width, ' ');
}