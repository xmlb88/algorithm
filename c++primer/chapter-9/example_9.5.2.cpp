#include <iostream>
#include <string>
using namespace std;

// page 321
int main() {
    string s = "hello";
    s.insert(s.size(), 5, '!');
    cout << "在s末尾插入5个感叹号: " << s << endl;
    s.erase(s.size() - 5, 5);
    cout << "从s删除最后5个字符: " << s << endl;

    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7);
    cout << "s.assign from char*: " << s << endl;
    s.insert(s.size(), cp + 7);
    cout << "s.insert from char*: " << s << endl;

    s = "some string";
    string s2 = "some other string";
    s.insert(0, s2);
    cout << "在s中位置0之前插入s2的拷贝: " << s << endl;
    s.insert(0, s2, 0, s2.size());
    cout << "在s[0]之前插入s2中s2[0]开始的s2.size()个字符: " << s << endl;
    return 0;
}
