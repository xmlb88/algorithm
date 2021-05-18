#include <iostream>
#include <string>
#include <vector>
using namespace std;

// start page: 527

// basic��������Quote; bulk��������Bulk_quote
print_total(cout, basic, 20);   // ����Quote��net_price
print_total(cout, bulk, 20);    // ����Bulk_quote��net_price


// Quote��Ķ��壺
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // ���ظ����������鼮�������ܶ�
    // �����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote() = default; // �������������ж�̬��
private:
    std::string bookNo;
protected:
    double price = 0.0; // ��ͨ״̬�²����۵ļ۸�
};

class Bulk_quote::public Quote {    // Bulk_quote�̳���Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    // ���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;    // ʹ���ۿ����ߵ���͹�����
    double discount = 0.0;  // ��С����ʾ���ۿ۶�
};


Quote item; // �������
Bulk_quote bulk;    // ���������
Quote *p = &item;   // pָ��Quote����
p = &bulk;  // pָ��bulk��Quote����
Quote &r = bulk;    // r�󶨵�bulk��Quote����


// Bulk_quote���캯��������4������
Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) {}

// ����ﵽ�˹����鼮��ĳ���������ֵ���Ϳ��������ۿۼ۸�
double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// �̳��뾲̬��Ա
class Base {
public:
    static void statmem();
};
class Derived : public Base {
    void f(const Derived&);
};

// ��̬��Ա��ѭͨ�õķ��ʿ��ƹ����������ĳ�Ա��private�ģ�����������Ȩ������
// ����ĳ��̬��Ա�ǿɷ��ʵģ������Ǽ���ͨ������ʹ����Ҳ��ͨ��������ʹ����

void Derived::f(const Derived &derived_obj) {
    Base::statmem();    // ��ȷ��Base������statmem
    Derived::statmem(); // ��ȷ��Derived�̳���statmem
    // ��ȷ��������Ķ����ܷ��ʻ���ľ�̬��Ա
    derived_obj.statmem();  // ͨ��Derived�������
    statmem();  // ͨ��this�������
}

class Bulk_quote : public Quote;    // ���������б��ܳ���������
class Bulk_quote;   // ��ȷ

// ��ֹ�̳�
class NoDerived final {};   // �ؼ���final��NoDerived������Ϊ����
class Base {};
// Last��final�ģ����ǲ��ܼ̳�Last
class Last final : Base {}; // Last������Ϊ����
class Bad : NoDerived {};   // ����NoDerived��final��
class Bad2 : Last {};   // ����Last��final��