#include <iostream>
#include <string>
using namespace std;

int main() {
    int i = 42;
    string s = to_string(i);    // 整数i转换为字符串
    cout << "s: " << s << endl;
    double d = stod(s); // 字符串s转换为浮点数
    cout << "d: " << d << endl;

    // 转换s中以数字开始的第一个子串，结果d=3.14
    string s2 = "pi = 3.14";
    d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    cout << "d2: " << d << endl;

    /* 
        to_string(val)
        stoi(s, p, b)
        stol(s, p, b)
        stoul(s, p, b)
        stoll(s, p, b)
        stoull(s, p, b)
        stof(s, p)
        stod(s, p)
        stold(s, p)
     */
}