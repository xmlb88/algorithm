#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    // back_inserter ͷ�ļ�iterator

    vector<int> vec; // ������
    auto it = back_inserter(vec);
    // ͨ������ֵ�ὫԪ����ӵ�vec��
    *it = 42;
    // vec��������һ��Ԫ�أ�ֵΪ42

    fill_n(back_inserter(vec), 10, 0);
    // ��ȷ��back_inserter����һ���������������������vec���Ԫ��


    // copy
    // ����������������ǰ2����ʾ���뷶Χ����������ʾĿ�����е���ʼλ��
    // ��Ҫ�����ݸ�copy��Ŀ����������Ҫ��������������һ�����Ԫ��

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    // a2��a1��Сһ��
    auto ret = copy(begin(a1), end(a1), begin(a2));

    // replace(ilst.begin(), ilst.end(), 0, 42);
    // replace_copy(ilst.cbegin(), ilst.cend(), 
    // back_inserter(ivec), 0, 42);

    
}