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