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


void reset_with_unique() {
    if (!p.unique()) {
        p.reset(new string(*p));    // ���ǲ���Ψһ�û��������µĿ���
    }
    *p += newVal;   //������Ψһ�û������Ըı�����ֵ
}


// ��Ҫ������ָͨ�������ָ��

void process(shared_ptr<int> ptr) { // ֵ���ݣ�ʵ�ο�����ptr�У������������ü���
    // ʹ��ptr
}   // ptr�뿪�����򣬱�����

// ��process���й����У����ü���ֵ����Ϊ2����process����ʱ��ptr�����ü�����ݼ����������Ϊ0��
// ���ֲ�����ptr������ʱ��ptrָ����ڴ治���ͷ�

// ��ȷ����
shared_ptr<int> p(new int(42));
process(p);
int i = *p; // ��ȷ�����ü���ֵΪ1

// ���ܴ��ݸ�processһ������ָ�룬�����Դ��ݸ���һ����ʱ��shared_ptr
// shared_ptr����һ������ָ�빹��ģ����ǣ��������ܿ��ܻᵼ�´���
int *x(new int(1024)); // x����ָͨ�룬
process(x); //���󣬲��ܽ�int*ת��Ϊһ��shared_ptr<int>
process(shared_ptr<int>(x));    //�Ϸ��ģ����ڴ�ᱻ�ͷ�
int j = *x; // δ���壬x��һ������ָ��




int main() {
    return 0;
}

// practice_12.10:
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
/* ��ȷ��shared_ptr<int>(p) �ᴴ��һ����ʱ������ָ
�룬�������ָ���� p ����ͬһ�����󣬴�ʱ���ü���Ϊ 2�������ʽ����ʱ����ʱ������ָ�뱻���٣���ʱ���ü���Ϊ 1 */

// practice_12.11:
process(shared_ptr<int>(p.get()));