#include <iostream>
#include <forward_list>
using namespace std;

void deleteOdd() {
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();        // 表示flst的首前元素
    auto curr = flst.begin();               // 表示flst中的第一个元素
    while (curr != flst.end()) {            // 仍有元素要处理
        if (*curr % 2)                      // 若元素为奇数
            curr = flst.erase_after(prev);  // 删除它并移动curr
        else {
            prev = curr;                    // 移动迭代器，prev指向curr之前的元素
            ++curr;                         // curr指向下一元素
        }
    }
}