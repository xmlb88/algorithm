#include <iostream>
#include <string>
using namespace std;

int main() {
    // string s;
    // cin >> s;
    // cout << s << endl;
    // cout << cin.good() << endl;
    // cout << cin.rdstate() << endl;

    // auto old_state = cin.rdstate()  // ��סcin�ĵ�ǰ״̬
    // cin.clear();                    // ʹcin��Ч
    // process_input(cin);             // ʹ��cin
    // cin.setstate(old_state);        // ��cin��Ϊԭ��״̬

    // cout << "hi!" << endl;  // ���hi��һ�����У�Ȼ��ˢ�»�����
    // cout << "hi!" << flush; // ���hi��Ȼ��ˢ�»��������������κζ����ַ�
    // cout << "hi!" << ends;  // ���hi��һ�����ַ���Ȼ��ˢ�»�����
    // cout << "hi";

    cout << unitbuf; // ������������󶼻�����ˢ�»�����
    // �κ����������ˢ�£��޻���
    cout << nounitbuf;  // �ص������Ļ��巽ʽ
    // ������������������������ᱻˢ��

    // ��������������

    // 282
    cin.tie(&cout); // ��չʾ����׼�⽫cin��cout������һ��
    // old_tieָ��ǰ������cin����������еĻ���
    ostream *old_tie = cin.tie(nullptr);
    *old_tie << "tie success" << endl;  // cin����������������
    // ��cin��cerr������not a good idea����ΪcinӦ�ù�����cout
    cin.tie(&cerr); // ��ȡcin��ˢ��cerr������cout
    cin.tie(old_tie);   // �ؽ�cin��cout�����������
}