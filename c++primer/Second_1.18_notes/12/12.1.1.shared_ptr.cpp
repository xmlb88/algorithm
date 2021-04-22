#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

void t_shared_ptr() {
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;

    // 如果p1不为空，检查它是否指向一个空string
    if (p1 && p1 -> empty())
        *p1 = "hi"; // 如果p1指向一个空string，解引用p1，将一个新值赋予string

    /* 
    shared_ptr<T> sp;
    unique_ptr<T> up;
    p;
    *p;
    p -> mem 等价于 (*p).mem
    p.get();
    swap(p, q);
    p.swap(q);
    
     */


    // shared_ptr独有的操作
    // make_shared<T>(args)
    // 返回一个shared_ptr,指向一个动态分配的类型为T的对象，使用args初始化此对象
    auto p = make_shared<stirng>("this");
    // shared_ptr<T>p(q)
    // p是shared_ptr q的拷贝：此操作会递增q中的计数器，q中的指针必须能转换成T*
    shared_ptr<string> p(q);
    // p = q
    p.unique(); // 若p.use_count()为1，返回true，否则返回false
    p.use_count(); // 返回与p共享对象的智能指针数量；可能很慢，主要用于调试

}