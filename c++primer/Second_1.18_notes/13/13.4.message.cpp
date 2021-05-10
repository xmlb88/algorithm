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

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)
        f -> addMsg(this);
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for (auto f : folders)
        f -> remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f -> remMsg(&lhs);
    for (auto f : rhs.folders)
        f -> remmsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}