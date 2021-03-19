#include <iostream>
#include <string>
using namespace std;

int main() {
    const char *cp = "Hello World!!!"; // 以空字符结束的数组
    char noNull[] = {'H', 'i'}; // 不是以空字符结束
    string s1(cp);  // 拷贝cp中的字符直到遇到空字符; s1 = "Hello World!!!";
    cout << "s1: " << s1 << endl;
    string s2(noNull, 2);   // 从noNull拷贝2个字符，s2 = "Hi";
    cout << "s2: " << s2 << endl;
    string s3(noNull);  // 未定义：noNull不是以空字符结束
    cout << "s3: " << s3 << endl;
    string s4(cp + 6, 5);   // 从cp[6]开始拷贝5个字符，s4 = "world"
    cout << "s4: " << s4 << endl;

    // 从string拷贝
    string s5(s1, 6, 5);
    string s6(s1, 6);
    string s7(s1, 6, 20);
    try
    {
        string s8(s1, 16);  // 抛出out_of_range异常
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    string s("this is test");
    string s10 = s.substr(0, 6);
    cout << "s10: " << s10 << endl;
    string s11 = s.substr(6);
    cout << "s11: " << s11 << endl;
    string s12 = s.substr(6, 11);
    string s13 = s.substr(12);
    
}