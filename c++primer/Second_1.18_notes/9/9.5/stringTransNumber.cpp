#include <iostream>
#include <string>
using namespace std;

int main() {
    int i = 42;
    string s = to_string(i);    // ����iת��Ϊ�ַ���
    cout << "s: " << s << endl;
    double d = stod(s); // �ַ���sת��Ϊ������
    cout << "d: " << d << endl;

    // ת��s�������ֿ�ʼ�ĵ�һ���Ӵ������d=3.14
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