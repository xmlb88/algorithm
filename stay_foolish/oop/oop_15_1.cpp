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
    // ���ظ����������鼮�������ܶ�
    // �����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
    virtual double net_price(std::size_t n) const
                    { return n * price; }
    virtual ~Quote() = default; // �������������ж�̬��

private:
    std::string bookNo; // �鼮��ISBN��
protected:
    double price = 0.0; // ������ͨ״̬�²����۵ļ۸�
};


class Bulk_quote : public Quote { // �������б�
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
                Quote(book, p), min_qty(qty), discount(disc) {}
    // ���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
    double net_price(std::size_t cnt) const override {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    std::size_t min_qty = 0;    // �����ۿ����ߵ���͹�����
    double discount = 0.0;  // ��С����ʾ���ۿ۶�
};

// ���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total(ostream &os, const Quote &item, size_t n) {
    // ���ݴ���item�²εĶ������͵���Quote::net_price
    // ����Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // ����Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}