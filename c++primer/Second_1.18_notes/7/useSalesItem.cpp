#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
    // Sales_data total;
    // if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    //     Sales_data trans;
    //     while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
    //         if (total.isbn() == trans.isbn()) {
    //             total.combine(trans);
    //         } else {
    //             cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    //             total = trans;
    //         }
    //     }
    //     cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    // } else {
    //     cerr << "No data ?!" << endl;
    //     return -1;
    // }
    // return 0;

    // Sales_data total();
    // if (read(cin, total)) {
    //     Sales_data trans;
    //     while (read(cin, trans)) {
    //         if (total.isbn() == trans.isbn()) {
    //             total = add(total, trans);
    //         } else {
    //             print(cout, total);
    //             total = trans;
    //         }
    //     }
    //     print(cout, total);
    // } else {
    //     cerr << "No data ?!" << endl;
    //     return -1;
    // }
    // return 0;

    // 使用istream构造函数
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        istream &is = cin;
        while (is) {
            Sales_data trans(is);
            if (!is) break;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data ?!" << endl;
        return -1;
    }
    return 0;
}