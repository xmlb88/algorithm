#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
v = {"a", "an", "the"};

// ͬ��������������ӵ�StrVec����
class StrVec {
public:
    StrVec &operaotr=(std::initializer_list<std::string>);
}

StrVec &StrVec::operator=(initializer_list<string> il) {
    // alloc_n_copy�����ڴ�ռ䲢�Ӹ�����Χ�ڿ���Ԫ��
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    retur *this;
}

// ���ϸ�ֵ�����

// ��Ϊ��Ա�Ķ�Ԫ�����������������󶨵���ʽ��thisָ��
// �ٶ����������ʾ����ͬһ����
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}