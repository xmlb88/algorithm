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
*   isalnum(), ��ĸ����
*   isalpha(), ��ĸ
*   isblank(), �ո��ˮƽ�Ʊ��
*   iscntrl(), �����ַ�
*   isdigit(), ���֣�0-9��
*   isgraph(), ���ո�֮��Ĵ�ӡ�ַ�
*   islower(), Сд��ĸ
*   isprint(), ��ӡ�ַ��������ո�
*   ispunct(), ������
*   isspace(), ��׼�հ��ַ����ո񣬽�ֽ�����з����س���ˮƽ����ֱ�Ʊ����
*   isupper(), ��д��ĸ
*   isxdigit(), ʮ���������֣�0-9��a-f��A-F��
*   tolower(), �����д��ĸ������Сд
*   toupper(), ���Сд��ĸ�������д
*/