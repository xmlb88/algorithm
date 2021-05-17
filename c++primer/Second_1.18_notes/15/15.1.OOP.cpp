#include <iostream>
#include <string>
#include <vector>
using namespace std;

// start page: 527

// basic的类型是Quote; bulk的类型是Bulk_quote
print_total(cout, basic, 20);   // 调用Quote的net_price
print_total(cout, bulk, 20);    // 调用Bulk_quote的net_price


// Quote类的定义：
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote() = default; // 对析构函数进行动态绑定
private:
    std::string bookNo;
protected:
    double price = 0.0; // 普通状态下不打折的价格
};

class Bulk_quote::public Quote {    // Bulk_quote继承自Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;    // 使用折扣政策的最低购买量
    double discount = 0.0;  // 以小数表示的折扣额
};