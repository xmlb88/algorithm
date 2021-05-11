#include <iostream>
#include <vector>
using namespace std;

// ������������<<
ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

// �����������������Ƿǳ�Ա����
Sales_data data;
data << cout;   // ���operator<<��Sales_data�ĳ�Ա
// һ������Ϊ��Ԫ

// �������������>>
// example
istream &operator>>(istream &is, Sales_data &item) {
    double price;   // ����Ҫ��ʼ������Ϊ���ǽ��ȶ������ݵ�price��֮����ʹ����
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // ��������Ƿ�ɹ�
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();    // ����ʧ�ܣ����󱻸���Ĭ�ϵ�״̬
    return is;
}