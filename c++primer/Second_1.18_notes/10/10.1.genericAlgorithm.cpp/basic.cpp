#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/* 
    大多数算法定义在头文件algorithm中，numeric定义一组数值泛型算法

 */

int main() {
    // vector<int> 是否包含特定值，调用标准库算法find
    vector<int> vec{1, 2, 3, 42, 5};
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val
        << (result == vec.end() ? " is not present " : " is present") << endl;

    // list<string> 中find
    list<string> lst{"this", "is", "a", "test", "a value"};
    string val1 = "a value";
    auto list_result = find(lst.cbegin(), lst.cend(), val1);
    if (list_result != lst.cend()) {
        cout << "lst find " << *list_result << endl;
    }
}