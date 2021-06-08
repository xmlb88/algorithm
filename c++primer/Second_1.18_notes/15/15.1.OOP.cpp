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


// 539��ʹ�������������ǿ��ִ���麯����ĳ���汾
// ǿ�е��û����ж���ĺ����汾������baseP�Ķ�̬���͵�����ʲô
double undiscounted = baseP -> Quote::net_price(42);


// 15.4 ������� page:541
// ���ڱ����ۿ�ֵ�͹��������࣬������ʹ����Щ���ݿ���ʵ�ֲ�ͬ�ļ۸����
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
            Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;   // �ۿ����õĹ�����
    double discount = 0.0;  // ��ʾ�ۿ۵�С��ֵ
};

// Disc_quote�����˴��麯������Bulk_quote�����Ǹú���
Disc_quote discounted;  // ���󣺲��ܶ���Disc_quote�Ķ���
Bulk_quote bulk;    // ��ȷ��Bulk_quote��û�д��麯��


// ����ʵ��Bulk_quote
// ��ͬһ�鼮�����۳���ĳ��ֵʱ�����ۿ�
// �ۿ۵�ֵʱһ��С��1������С��ֵ���Դ��������������ۼ۸�
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
    int prot_mem;   // protected��Ա
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);   // �ܷ���Sneaky::prot_mem
    friend void clobber(Base&); // ���ܷ���Base::prot_mem
    int j;  // jĬ����private
};

// ��ȷ��clobber�ܷ���Sneaker�����private��protected��Ա
void clobber(Sneaky &s) {s.j = s.prot_mem = 0;}
// ����clobber���ܷ���Base��protected��Ա
void clobber(Base &b) {b.prot_mem = 0;}
// �ܱ����� ��Ա "Base::prot_mem" (������ ��������:132) ����ͨ�� "Base" ָ���������C/C++(410)


// 543 
class Base {
public:
    void pub_mem(); // public��Ա
protected:
    int prot_mem;   // protected��Ա
private:
    char priv_mem;  // private��Ա
};

struct Pub_Derv : public Base {
    // ��ȷ���������ܷ���protected��Ա
    int f() {return prot_mem;}
    // ����private��Ա������������˵�ǲ��ɷ��ʵ�
    char g() {return priv_mem;}
};

struct Priv_Derv : private Base {
    // private��Ӱ��������ķ���Ȩ��
    int f1() const {return prot_mem;}
};


class Base {
    // ���friend������������Ա��֮ǰ�İ汾һ��
    friend class pal;   // pal�ڷ���Base��������ʱ������������
};

class Pal {
public:
    int f(Base b) { return b.prot_mem; }    // ��ȷ��Pal��Base����Ԫ
    int f2(Sneaky s) { return s.j; }    // ����Pal����Sneaky����Ԫ
    // �Ի���ķ���Ȩ���ɻ��౾����ƣ���ʹ����������Ļ��ಿ��Ҳ�����
    int f3(Sneaky s) { return s.prot_mem; } // ��ȷ��Pal��Base����Ԫ
};