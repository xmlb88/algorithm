#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : 
                    bookNo(book), price(sales_price) {}

    std::string isbn() const { return boolNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const
                    { return n * price; }
    virtual ~Quote() = default; // 对析构函数进行动态绑定

private:
    std::string bookNo; // 书籍的ISBN号
protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};


class Bulk_quote : public Quote { // 类派生列表
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
                Quote(book, p), min_qty(qty), discount(disc) {}
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t cnt) const override {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    std::size_t min_qty = 0;    // 适用折扣政策的最低购买量
    double discount = 0.0;  // 以小数表示的折扣额
};

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const Quote &item, size_t n) {
    // 根据传入item新参的对象类型调用Quote::net_price
    // 或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // 调用Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}