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


// 539：使用作用域运算符强制执行虚函数的某个版本
// 强行调用基类中定义的函数版本而不管baseP的动态类型到底是什么
double undiscounted = baseP -> Quote::net_price(42);


// 15.4 抽象基类 page:541
// 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
            Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;   // 折扣适用的购买量
    double discount = 0.0;  // 表示折扣的小数值
};

// Disc_quote声明了纯虚函数，而Bulk_quote将覆盖该函数
Disc_quote discounted;  // 错误：不能定义Disc_quote的对象
Bulk_quote bulk;    // 正确：Bulk_quote中没有纯虚函数


// 重新实现Bulk_quote
// 当同一书籍的销售超过某个值时启用折扣
// 折扣的值时一个小于1的正的小数值，以此来降低正常销售价格
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc):
            Disc_quote(book, price, qty, disc) {}
    double net_price(std::size_t) const override;
};


// 543 15.5
class Base {
protected:
    int prot_mem;   // protected成员
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);   // 能访问Sneaky::prot_mem
    friend void clobber(Base&); // 不能访问Base::prot_mem
    int j;  // j默认是private
};

// 正确：clobber能访问Sneaker对象的private和protected成员
void clobber(Sneaky &s) {s.j = s.prot_mem = 0;}
// 错误：clobber不能访问Base的protected成员
void clobber(Base &b) {b.prot_mem = 0;}
// 受保护的 成员 "Base::prot_mem" (已声明 所在行数:132) 不能通过 "Base" 指针或对象访问C/C++(410)


// 543 
class Base {
public:
    void pub_mem(); // public成员
protected:
    int prot_mem;   // protected成员
private:
    char priv_mem;  // private成员
};

struct Pub_Derv : public Base {
    // 正确：派生类能访问protected成员
    int f() {return prot_mem;}
    // 错误：private成员对于派生类来说是不可访问的
    char g() {return priv_mem;}
};

struct Priv_Derv : private Base {
    // private不影响派生类的访问权限
    int f1() const {return prot_mem;}
};


class Base {
    // 添加friend声明，其他成员与之前的版本一致
    friend class pal;   // pal在访问Base的派生类时不具有特殊性
};

class Pal {
public:
    int f(Base b) { return b.prot_mem; }    // 正确：Pal是Base的友元
    int f2(Sneaky s) { return s.j; }    // 错误：Pal不是Sneaky的友元
    // 对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
    int f3(Sneaky s) { return s.prot_mem; } // 正确：Pal是Base的友元
};