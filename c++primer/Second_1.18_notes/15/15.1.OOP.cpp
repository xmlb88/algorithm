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


Quote item; // 基类对象
Bulk_quote bulk;    // 派生类对象
Quote *p = &item;   // p指向Quote对象
p = &bulk;  // p指向bulk的Quote部分
Quote &r = bulk;    // r绑定到bulk的Quote部分


// Bulk_quote构造函数，接受4个参数
Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) {}

// 如果达到了购买书籍的某个最低限量值，就可以享受折扣价格
double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// 继承与静态成员
class Base {
public:
    static void statmem();
};
class Derived : public Base {
    void f(const Derived&);
};

// 静态成员遵循通用的访问控制规则，如果基类的成员是private的，则派生类无权访问它
// 假设某静态成员是可访问的，则我们既能通过基类使用它也能通过派生类使用它

void Derived::f(const Derived &derived_obj) {
    Base::statmem();    // 正确：Base定义了statmem
    Derived::statmem(); // 正确：Derived继承了statmem
    // 正确：派生类的对象能访问基类的静态成员
    derived_obj.statmem();  // 通过Derived对象访问
    statmem();  // 通过this对象访问
}

class Bulk_quote : public Quote;    // 错误：派生列表不能出现在这里
class Bulk_quote;   // 正确

// 防止继承
class NoDerived final {};   // 关键字final，NoDerived不能作为基类
class Base {};
// Last是final的，我们不能继承Last
class Last final : Base {}; // Last不能作为基类
class Bad : NoDerived {};   // 错误：NoDerived是final的
class Bad2 : Last {};   // 错误：Last是final的