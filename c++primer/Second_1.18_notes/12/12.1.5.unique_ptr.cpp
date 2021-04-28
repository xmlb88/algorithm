#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// ��ʼ��(����ʹ��ֱ�ӳ�ʼ����ʽ)
void t_unique_ptr_init() {
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));
}

// ��֧����ͨ�Ŀ�����ֵ����
void t_unique_ptr() {
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1);  // ����unique_ptr��֧�ֿ���
    unique_ptr<string> p3;
    p3 = p2;    // ����unique_ptr��֧�ָ�ֵ
}

unique_ptr<T> u1;
unique_ptr<T, D> u2;

unique_ptr<T, D> u(d);
u = nullptr;
u.release(); // u������ָ��Ŀ���Ȩ������ָ�룬����u�ÿ�
u.reset(q);
u.reset(nullptr);

unique_ptr<string> p2(p1.release());
unique_ptr<string> p3(new string("Trex"));
p2.reset(p3.release());

p2.release();   // ����, p2�����ͷ��ڴ棬�������Ƕ�ʧ��ָ��
auto p = p2.release();  // ��ȷ�������Ǳ���ǵ�delete(p)

// ����unique_ptr�����ͷ���unique_ptr
// ���ܿ���unique_ptr�Ĺ�����һ�����⣺���ǿ��Կ�����ֵһ����Ҫ������unique_ptr,

unique_ptr<int> clone(int p) {
    // ��ȷ����int*����һ��unique_ptr<int>
    return unique_ptr<int>(new int(p));
}

// 421