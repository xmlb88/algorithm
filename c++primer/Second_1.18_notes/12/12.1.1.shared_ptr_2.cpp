#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// make_shared
void t_make_shared() {
    shared_ptr<int> p3 = make_shared<int>(42);
    cout << *p3 << endl;
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    cout << *p4 << endl;
    shared_ptr<int> p5 = make_shared<int>();
    cout << *p5 << endl;
    // ����˳��������emplace��Ա������ֵ��ʼ����������<T>��ĳ�����캯��ƥ��
    // auto 
    auto p6 = make_shared<vector<string>>(vector<string>({"1", "@", "A"}));
    for (auto _c : *p6) {
        cout << _c << endl;
    }
}

// shared_ptr�Ŀ����͸�ֵ
void ce_shared_ptr() {
    auto p = make_shared<int>(42);  // pָ��Ķ���ֻ��pһ��������
    cout << p.use_count() << " " << p.unique() << endl;
    auto q(p);  // p��qָ����ͬ�Ķ��󣬴˶�����2��������
    cout << p.use_count() << " " << q.use_count() << " " << p.unique() << " " << q.unique() << endl;

    // ���ü��� reference count
    // shared_ptr�ļ�������Ϊ0�� �Զ��ͷ��Լ�����Ķ���
    auto r = make_shared<int> (42); // rָ���intֻ��һ��������
    r = q;  // ��r��ֵ������ָ����һ����ַ
            // �ݼ�rԭ��ָ��Ķ�������ü���
            // rԭ��ָ��Ķ�����û�������ߣ����Զ��ͷ�

    // shared_ptr�������������ݼ�ָ���������ü�����������ü�����Ϊ0���Զ����ٶ����ͷ��ڴ�

}

shared_ptr<Foo> factory(T arg) {
    // ǡ������arg
    // shared_ptr�����ͷ��ڴ�
    return make_shared<Foo>(arg);
}

void use_factory(T arg) {
    shared_ptr<Foo> p = factory(arg);
    // ʹ��p
    // return p;
}   // p�뿪��������ָ����ڴ�ᱻ�Զ��ͷ�


int main() {
    // t_make_shared();
    ce_shared_ptr();
}