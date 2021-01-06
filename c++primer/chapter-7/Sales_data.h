#include <iostream>
#include <string>
using namespace std;

class Sales_data {
// 为Sales_data的非成员函数所做的友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:     // 访问说明符

    // 新增构造函数
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) :
              bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(istream &);

    // 其他成员
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:    // 访问说明符
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);