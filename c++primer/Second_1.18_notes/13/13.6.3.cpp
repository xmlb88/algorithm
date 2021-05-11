#include <iostream>
#include <vector>
using namespace std;

class StrVec {
public:
    void push_back(const std::string&); // ����Ԫ��
    void push_back(std::string&&);  // �ƶ�Ԫ��
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
    Foo &operator=(const Foo&) &;   // ֻ������޸ĵ���ֵ��ֵ
};

Foo &Foo::operator=(const Foo &rhs) & {
    return *this; 
}

Foo &retFoo();  // ����һ�����ã�retFoo������һ����ֵ
Foo retVal();   // ����һ��ֵ��retVal������һ����ֵ
Foo i, j;   // i��j����ֵ
i = j;  // ��ȷ��i����ֵ
retFoo() = j;   // ��ȷ��retFoo()����һ����ֵ
retVal() = j;   // ����retVal()����һ����ֵ
i = retVal();   // ��ȷ�����Խ�һ����ֵ��Ϊ��ֵ�������Ҳ��������

class Foo {
public:
    Foo sorted() &&;    // �����ڿɸı����ֵ
    Foo sorted() const &;   // �������κ����͵�Foo
private:
    vector<int> data;
};

// ������Ϊ��ֵ����˿���ԭַ����
Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}

// ��������const����һ����ֵ������������Ƕ����ܶ������ԭַ����
Foo Foo::sorted() const & {
    Foo ret(*this); // ����һ������
    sort(ret.data.begin(), ret.data.end()); // ���򸱱�
    return ret;
}

retVal().sorted();  // retVal()��һ����ֵ������Foo::sorted() &&
retFoo().sorted();  // retFoo()��һ����ֵ������Foo::sorted() const &
