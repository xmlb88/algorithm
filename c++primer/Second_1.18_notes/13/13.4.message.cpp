#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Folder.h"
using namespace std;

class Message {
    friend class Folder;
public:
    // folders被隐式初始化为空集合
    explicit Message(const std::string &str = ""):
        contents(str) {}
    // 拷贝控制成员，用来管理指向本Message的指针
    Message(const Message&);    // 拷贝构造函数
    Message& operator=(const Message&); // 拷贝赋值运算符
    ~Message();
    // 从给定Folder集合中添加/删除本Message
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;   // 实际消息文本
    std::set<Folder*> folders;  // 包含本Message的Folder
    // 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    // 将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    // 从folders中的每个Folder中删除本Message
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