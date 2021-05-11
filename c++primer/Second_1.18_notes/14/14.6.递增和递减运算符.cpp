#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ǰ�õ���/�ݼ������
class StrBlobPtr {
public:
    // �����͵ݼ������
    StrBlobPtr& operator++();   // ǰ�������
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int); // ���������
    StrBlobPtr operator--(int);
};

StrBolbPtr& StrBolbPtr::operator++() {
    // ���curr�Ѿ�ָ����������β��λ�ã����޷�������
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // ��curr�ڵ�ǰ״̬����ǰ�ƶ�һ��Ԫ��
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    // ���curr��0��������ݼ���������һ����Ч�±�
    --curr; // ��curr�ڵ�ǰ״̬������ƶ�һ��Ԫ��
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

// ���������
// �ڵ�������֮ǰ��Ҫ���ȼ�¼�����״̬
StrBlobPtr StrBlobPtr::operator++(int) {
    // �˴���������Ч�ԣ�����ǰ�õ�������ʱ����Ҫ���
    StrBlobPtr ret = *this; // ��¼��ǰ��ֵ
    ++*this;    // ��ǰ�ƶ�һ��Ԫ�أ�ǰ��++��Ҫ����������Ч��
    return ret; // ����֮ǰ��¼��״̬
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

// ��ʾ�ص��ú��������
StrBlobPtr p(a1);
p.operator++(0);    // ���ú��ð汾��operator++
p.operator++(); // ����ǰ�ð汾��operator++