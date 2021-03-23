#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    // back_inserter 头文件iterator

    vector<int> vec; // 空向量
    auto it = back_inserter(vec);
    // 通过它赋值会将元素添加到vec中
    *it = 42;
    // vec中现在有一个元素，值为42

    fill_n(back_inserter(vec), 10, 0);
    // 正确，back_inserter创建一个插入迭代器，可用来向vec添加元素


    // copy
    // 接受三个迭代器，前2个表示输入范围，第三个表示目的序列的起始位置
    // 重要：传递给copy的目的序列至少要包含与输入序列一样多的元素

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    // a2与a1大小一样
    auto ret = copy(begin(a1), end(a1), begin(a2));

    // replace(ilst.begin(), ilst.end(), 0, 42);
    // replace_copy(ilst.cbegin(), ilst.cend(), 
    // back_inserter(ivec), 0, 42);

    
}