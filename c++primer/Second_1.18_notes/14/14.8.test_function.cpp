#include <iostream>
#include <vector>
#include <functional>
#include <map>
using namespace std;

int add(int i, int j) { return i + j; }

class divide {
public:
    int operator() (int i, int j) {
        return i / j;
    }
};

auto mod = [] (int i, int j) { return i % j; };

map<string, function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [] (int i, int j) {return i * j;}},
    {"/", divide()},
    {"%", mod}
};

int main() {
    cout << "i + j = " << binops["+"](10, 3) << endl;
    cout << "i - j = " << binops["-"](10, 3) << endl;
    cout << "i * j = " << binops["*"](10, 3) << endl;
    cout << "i / j = " << binops["/"](10, 3) << endl;
    cout << "i % j = " << binops["%"](10, 3) << endl;
}