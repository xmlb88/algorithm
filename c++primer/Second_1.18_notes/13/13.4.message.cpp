#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Folder.h"
using namespace std;

class Message {
    friend class Folder;
public:
    // folders����ʽ��ʼ��Ϊ�ռ���
    explicit Message(const std::string &str = ""):
        contents(str) {}
    // �������Ƴ�Ա����������ָ��Message��ָ��
    Message(const Message&);    // �������캯��
    Message& operator=(const Message&); // ������ֵ�����
    ~Message();
    // �Ӹ���Folder���������/ɾ����Message
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;   // ʵ����Ϣ�ı�
    std::set<Folder*> folders;  // ������Message��Folder
    // �������캯����������ֵ�����������������ʹ�õĹ��ߺ���
    // ����Message��ӵ�ָ�������Folder��
    void add_to_Folders(const Message&);
    // ��folders�е�ÿ��Folder��ɾ����Message
    void remove_from_Folders();
};

// 461