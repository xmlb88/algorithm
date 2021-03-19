#include <iostream>
#include <string>
using namespace std;

int main() {
    const char *cp = "Hello World!!!"; // �Կ��ַ�����������
    char noNull[] = {'H', 'i'}; // �����Կ��ַ�����
    string s1(cp);  // ����cp�е��ַ�ֱ���������ַ�; s1 = "Hello World!!!";
    cout << "s1: " << s1 << endl;
    string s2(noNull, 2);   // ��noNull����2���ַ���s2 = "Hi";
    cout << "s2: " << s2 << endl;
    string s3(noNull);  // δ���壺noNull�����Կ��ַ�����
    cout << "s3: " << s3 << endl;
    string s4(cp + 6, 5);   // ��cp[6]��ʼ����5���ַ���s4 = "world"
    cout << "s4: " << s4 << endl;

    // ��string����
    string s5(s1, 6, 5);
    string s6(s1, 6);
    string s7(s1, 6, 20);
    try
    {
        string s8(s1, 16);  // �׳�out_of_range�쳣
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