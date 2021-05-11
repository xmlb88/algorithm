#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StrBlobPtr {
public:
    std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];  // (*p)�Ƕ�����ָ��vector
    }
    std::string* operator->() const {
        // ��ʵ�ʹ���ί�и������������
        return & this->operator*();
    }
}

// 
StrBlob a1 = {"hi", "bye", "now"};
StrBlobPtr p(a1);   // pָ��a1�е�vector
*p = "okey";    // ��a1����Ԫ�ظ�ֵ
cout << p->size() << endl;
cout << (*p).size() << endl;