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

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);    // 使用set的移动复制运算符
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

// 移动迭代器 move iterator
void StrVec::reallocate() {
    // 分配大小2倍于当前规模的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // 移动元素
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}