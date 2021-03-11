#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
// 为非成员函数所做的友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data&);

public:
    // 新增构造函数
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);
    // Sales_data(std::istream &is) { read(is, *this); }

    // 新成员
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
    // 之前的数据
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold; // 把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}

std::istream& read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

#endif