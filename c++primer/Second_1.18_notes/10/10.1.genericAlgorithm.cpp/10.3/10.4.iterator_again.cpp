#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

/* 
���������(insert iterator)
��������(stream iterator):���������󶨵������������ϣ�������������������IO��
���������(reverse iterator):��ǰ�ƶ�
�ƶ�������(move iterator)
 */


// ���������
back_inserter:// ʹ��push_back�ĵ�����
front_inserter:// ʹ��push_front�ĵ�����
inserter:// ʹ��insert�ĵ����������ܵڶ���������ָ����������ĵ�����

// ʹ��inserter
*it = val;
// ==
it = c.insert(it, val);
++it;

// front_inserter
list<int> lst = {1, 2, 3, 4};
list<int> lst2, lst3;
// ������ɺ�lst2����4, 3, 2, 1
copy(lst.cbegin(), lst.cend(), front_insert(lst2));
// ������ɺ�lst3����1, 2, 3, 4
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));


// iostream������

//363
// 359