#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

void t_shared_ptr() {
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;

    // ���p1��Ϊ�գ�������Ƿ�ָ��һ����string
    if (p1 && p1 -> empty())
        *p1 = "hi"; // ���p1ָ��һ����string��������p1����һ����ֵ����string

    /* 
    shared_ptr<T> sp;
    unique_ptr<T> up;
    p;
    *p;
    p -> mem �ȼ��� (*p).mem
    p.get();
    swap(p, q);
    p.swap(q);
    
     */


    // shared_ptr���еĲ���
    // make_shared<T>(args)
    // ����һ��shared_ptr,ָ��һ����̬���������ΪT�Ķ���ʹ��args��ʼ���˶���
    auto p = make_shared<stirng>("this");
    // shared_ptr<T>p(q)
    // p��shared_ptr q�Ŀ������˲��������q�еļ�������q�е�ָ�������ת����T*
    shared_ptr<string> p(q);
    // p = q
    p.unique(); // ��p.use_count()Ϊ1������true�����򷵻�false
    p.use_count(); // ������p������������ָ�����������ܺ�������Ҫ���ڵ���

}