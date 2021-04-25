#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void t_make_shared_ptr() {
    shared_ptr<double> p1;
    shared_ptr<int> p2(new int(42));    // p2ָ��һ��ֵΪ42��int
    // shared_ptr<int> p3 = new int(42);   // ���󣬱���ʹ��ֱ�ӳ�ʼ����ʽ
    shared_ptr<int> p4 (new int(1024));
}

// ����:��ʽת��Ϊshared_ptr<int>
// shared_ptr<int> clone(int p) {
//     return new int(p);
// }

shared_ptr<int> clone(int p) {
    // return shared_ptr<int>(new int(p));
    return make_shared<int>(p);
}

// ������get��ʼ����һ������ָ�룬��Ϊ����ָ�븳ֵ
shared_ptr<int> p(new int(42));
int *q = p.get();
{
    // δ���壬2��������shared_ptrָ����ͬ���ڴ�
    shared_ptr<int>(q);
}   // ����������q�����٣���ָ����ڴ汻�ͷ�
int foo = *p;   // δ���壺 pָ����ڴ��Ѿ����ͷ���

// ����������
p = new int(1024);   // ���󣺲��ܽ�һ��ָ�븳��shared_ptr
p.reset(new int(1024)); // ��ȷ��pָ��һ���¶���

int main() {
    return 0;
}