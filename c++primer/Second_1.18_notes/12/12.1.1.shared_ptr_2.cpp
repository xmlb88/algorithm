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
    // 类似顺序容器的emplace成员，进行值初始化，必须与<T>的某个构造函数匹配
    // auto 
    auto p6 = make_shared<vector<string>>(vector<string>({"1", "@", "A"}));
    for (auto _c : *p6) {
        cout << _c << endl;
    }
}

// shared_ptr的拷贝和赋值
void ce_shared_ptr() {
    auto p = make_shared<int>(42);  // p指向的对象只有p一个引用者
    cout << p.use_count() << " " << p.unique() << endl;
    auto q(p);  // p和q指向相同的对象，此对象有2个引用者
    cout << p.use_count() << " " << q.use_count() << " " << p.unique() << " " << q.unique() << endl;

    // 引用计数 reference count
    // shared_ptr的计数器变为0， 自动释放自己管理的对象
    auto r = make_shared<int> (42); // r指向的int只有一个引用者
    r = q;  // 给r赋值，令它指向另一个地址
            // 递减r原来指向的对象的引用计数
            // r原来指向的对象已没有引用者，会自动释放

    // shared_ptr的析构函数：递减指向对象的引用计数，如果引用计数变为0，自动销毁对象，释放内存

}

shared_ptr<Foo> factory(T arg) {
    // 恰当处理arg
    // shared_ptr负责释放内存
    return make_shared<Foo>(arg);
}

void use_factory(T arg) {
    shared_ptr<Foo> p = factory(arg);
    // 使用p
    // return p;
}   // p离开了作用域，指向的内存会被自动释放


int main() {
    // t_make_shared();
    ce_shared_ptr();
}