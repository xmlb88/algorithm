#include <iostream>
#include <forward_list>
using namespace std;

void deleteOdd() {
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();        // ��ʾflst����ǰԪ��
    auto curr = flst.begin();               // ��ʾflst�еĵ�һ��Ԫ��
    while (curr != flst.end()) {            // ����Ԫ��Ҫ����
        if (*curr % 2)                      // ��Ԫ��Ϊ����
            curr = flst.erase_after(prev);  // ɾ�������ƶ�curr
        else {
            prev = curr;                    // �ƶ���������prevָ��curr֮ǰ��Ԫ��
            ++curr;                         // currָ����һԪ��
        }
    }
}