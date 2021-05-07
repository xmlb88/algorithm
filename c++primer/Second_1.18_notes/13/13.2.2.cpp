#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ������Ϊ��ָ�����
class HasPtr {
public:
    // ���캯�������µ�string���µļ�����������������Ϊ1
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // �������캯�����������������ݳ�Ա��������������
    HasPtr(const HasPtr &p):
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;   // ������¼�ж��ٸ�������*ps�ĳ�Ա
};

HasPtr::~HasPtr() {
    if (--*use == 0) {  // ������ü�����Ϊ0
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use; // �����Ҳ������������ü���
    if (--*use == 0) {
        // Ȼ��ݼ�����������ü���
        delete ps;  // ���û�������û�
        delete use; // �ͷű��������ĳ�Ա
    }
    ps = rhs.ps;    // �����ݴ�rhs������������
    i = rhs.i;
    use = rhs.use;
    return *this;   // ���ر�����
}