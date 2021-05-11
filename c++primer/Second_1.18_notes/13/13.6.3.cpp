#include <iostream>
#include <vector>
using namespace std;

class StrVec {
public:
    void push_back(const std::string&); // 拷贝元素
    void push_back(std::string&&);  // 移动元素
};

void StrVec::push_back(const string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}


class Foo {
public:
    Foo &operator=(const Foo&) &;   // 只能向可修改的左值赋值
};

Foo &Foo::operator=(const Foo &rhs) & {
    return *this; 
}

Foo &retFoo();  // 返回一个引用，retFoo调用是一个左值
Foo retVal();   // 返回一个值，retVal调用是一个右值
Foo i, j;   // i和j是左值
i = j;  // 正确：i是左值
retFoo() = j;   // 正确：retFoo()返回一个左值
retVal() = j;   // 错误：retVal()返回一个右值
i = retVal();   // 正确：可以将一个右值作为赋值操作的右侧运算对象

class Foo {
public:
    Foo sorted() &&;    // 可用于可改变的右值
    Foo sorted() const &;   // 可用于任何类型的Foo
private:
    vector<int> data;
};

// 本对象为右值，因此可以原址排序
Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}

// 本对象是const或是一个左值，哪种情况我们都不能对其进行原址排序
Foo Foo::sorted() const & {
    Foo ret(*this); // 拷贝一个副本
    sort(ret.data.begin(), ret.data.end()); // 排序副本
    return ret;
}

retVal().sorted();  // retVal()是一个右值，调用Foo::sorted() &&
retFoo().sorted();  // retFoo()是一个左值，调用Foo::sorted() const &
