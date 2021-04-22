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
    auto p6 = make_shared<vector<string>>({"1", "@", "a"});
    for (auto _c : *p6) {
        cout << _c << endl;
    }
}

int main() {
    t_make_shared();
}