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


    int ia[] = {27, 210, 12, 47, 109, 83};
    int val2 = 83;
    int* result2 = find(begin(ia), end(ia), val2);
    cout << "find in ia: " << *result2 << endl;
    auto result3 = find(ia + 1, ia + 4, val2);

    // accumulate(vec.begin(), vec.end(), 0);
    // string sum = accumulate(v.cbegin(), v.cend(), string(""));

    // fill(vec.begin(), vec.end(), 0);
    // fill(vec.begin(), vec.begin() + vec.size() / 2, 10);

    // equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    // 340
}