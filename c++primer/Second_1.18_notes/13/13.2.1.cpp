#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ��ֵ�汾HasPtr
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    // ��psָ���string��ÿ��HasPtr�������Լ��Ŀ���
    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.ps);    // �����ײ�string
    delete ps;  // �ͷž��ڴ�
    ps = newp;  // ���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;   // ���ر�����
}

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);   // ����ָ�룬������string����
    swap(lhs.i, rhs.i);     // ����int��Ա
}

// inline
// void swap(HasPtr &lhs, HasPtr &rhs) {
//     using std::swap;
//     swap(lhs.ps, rhs.ps);
//     swap(lhs.i, rhs.i);
// }

// ʹ��swap���п�����������ɸ�ֵ����
// rhs��ֵ���ݣ���ζ��HasPtr�Ŀ������캯��
// ���Ҳ���������е�string������rhs
HasPtr& HasPtr::operator=(HasPtr rhs) {
    // ��������������;ֲ�����rhs������
    swap(*this, rhs);   // rhs����ָ�򱾶�������ʹ�õ��ڴ�
    return *this;   // rhs�����٣��Ӷ�delete��rhs�е�ָ��
}