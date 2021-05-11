#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StrBlobPtr {
public:
    std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];  // (*p)是对象所指的vector
    }
    std::string* operator->() const {
        // 将实际工作委托给解引用运算符
        return & this->operator*();
    }
}

// 
StrBlob a1 = {"hi", "bye", "now"};
StrBlobPtr p(a1);   // p指向a1中的vector
*p = "okey";    // 给a1的首元素赋值
cout << p->size() << endl;
cout << (*p).size() << endl;