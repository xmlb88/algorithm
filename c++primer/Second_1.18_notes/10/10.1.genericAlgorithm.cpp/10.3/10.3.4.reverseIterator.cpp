#include <iostream>
#include <string>
using namespace std;

string line = "apple,this";
auto comma = find(line.cbegin(), line.cend(), ',');
cout << string(line.cbegin(), comma) << endl;

// ��ӡ���һ������
auto rcomma = find(line.crbegin(), line.crend(), ',');
// ���󣺽�����������ʵ��ַ�
cout << string(line.crbegin(), rcomma) << endl;
// FIRST,MIDDLE,LAST
// �����TSAL
// reverse_iterator��base��Ա��ת���������Ӧ����ͨ������
// ��ȷ�ķ�ʽ
cout << string(rcomma.base(), line.cend()) << endl;
// ��ӡLAST
