#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
        s[index] = toupper(s[index]);
    }

    cout << s << endl;

    vector<int> v;
    for (int i; cin >> i; ) {
        v.push_back(i);
    }

    for (int a : v) {
        cout << a << " ";
    }
}

/* <cctype>
*   isalnum(), 字母数字
*   isalpha(), 字母
*   isblank(), 空格或水平制表符
*   iscntrl(), 控制字符
*   isdigit(), 数字（0-9）
*   isgraph(), 除空格之外的打印字符
*   islower(), 小写字母
*   isprint(), 打印字符（包括空格）
*   ispunct(), 标点符号
*   isspace(), 标准空白字符（空格，进纸，换行符，回车，水平、垂直制表符）
*   isupper(), 大写字母
*   isxdigit(), 十六进制数字（0-9，a-f，A-F）
*   tolower(), 如果大写字母返回其小写
*   toupper(), 如果小写字母返回其大写
*/