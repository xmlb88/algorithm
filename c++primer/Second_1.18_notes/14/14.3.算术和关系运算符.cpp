#include <iostream>
#include <vector>
using namespace std;

// ����Ч�ķ�ʽ��ʹ�ø��ϸ�ֵ���������������
Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;   // ��lhs�����ݳ�Ա������sum
    sum += rhs; // ��rhs�ӵ�sum��
    return sum; // ���������sum�ĸ���
}


// ��������
// example
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}


// ��ϵ�����
