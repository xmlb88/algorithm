#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

/* 
插入迭代器(insert iterator)
流迭代器(stream iterator):迭代器被绑定到输入或输出流上，可用来遍历所关联的IO流
反向迭代器(reverse iterator):向前移动
移动迭代器(move iterator)
 */


// 插入迭代器
back_inserter:// 使用push_back的迭代器
front_inserter:// 使用push_front的迭代器
inserter:// 使用insert的迭代器，接受第二个参数，指向给定容器的迭代器

// 使用inserter
*it = val;
// ==
it = c.insert(it, val);
++it;

// front_inserter
list<int> lst = {1, 2, 3, 4};
list<int> lst2, lst3;
// 拷贝完成后，lst2包含4, 3, 2, 1
copy(lst.cbegin(), lst.cend(), front_insert(lst2));
// 拷贝完成后，lst3包含1, 2, 3, 4
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));


// iostream迭代器

//363
// 359