#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <functional>
using namespace std;

// example
struct absInt {
    int operator() (int val) const {
        return val < 0 ? -val : val;
    }
};

// 使用
itnt i = -42;
absInt absObj;  // 含有函数调用运算符的对象
int ui = absObj(i); // 将i传递给absObj.operator()

// 函数对象 行为像函数一样


class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) {}
    void operator() (const string &s) const { os << s << sep; }
private:
    ostream &os;    // 用于写入的目的流
    char sep;   // 用于将不同输出隔开的字符
};

PrintString printer;    // 使用默认值，打印到cout
printer(s); // 在cout中打印s， 后面跟一个空格
PrintString errors(cerr, '\n');
errors(s);  // 在cerr中打印s，后面跟一个换行符

// 函数对象常常作为泛型算法的实参，例如：
for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

// *lambda是函数对象
stable_sort(words.begin(), words.end(), 
    [](const string &a, const string &b)
    { return a.size() < b.size(); });

// 其行为类似于下面这个类的一个未命名对象
class ShorterString {
public:
    bool operator() (const string &s1, const string &s2) cosnt {
        return s1.size() < s2.size();
    }
};

// 重写并重新调用stable_sort
stable_sort(words.begin(), words.end(), ShorterString());


// 表示lambda及相应捕获行为的类
auto wc = find_if(words.begin(), words.end(), [sz] (cosnt string &s) {
    return a.size() >= sz;
});

// 该lambda表达式产生的类将形如：
class SizeComp {
    SizeComp(size_t n) : sz(n) {}   // 该形参对应捕获的变量
    // 该调用运算符的返回类型、形参和函数体都与lambda一致
    bool operator() (const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;  // 该数据成员对应通过值捕获的变量
};

// 使用这个类必须提供一个实参
auto wc = find_if(words.begin(), words.end(), SizeComp(sz));




// 标准库定义的函数对象
plus<int> intAdd;   // 可执行int加法的函数对
negate<int> intNegate;  // 可对int值取反的函数对象
// 使用intAdd::operator(int, int)求10和20的和
int sum = intAdd(10, 20);
sum = intNegate(intAdd(10, 20));

sum = intAdd(10, intNegate(10));

// 在算法中使用标准库函数对象
sort(svec.begin(), svec.end(), greater<string>());

// 用于指针
vector<string*> nameTable;  // 指针的vector
// 错误：nameTable中的指针彼此之间没有关系，所以<将产生未定义的行为
sort(nameTable.beign(), nameTable.end(), [] (string *a, string *b) {
    return a < b;
});
// 正确：标准库规定指针的less是定义良好的
sort(nameTable.begin(), nameTable.end(), less<string*>());


// 可调用对象与function
// c++有几种可调用的对象：
// 函数、函数指针、lambda表达式、bind创建的对象以及重载了函数调用运算符的类
// 511

// 不同类型可能具有相同的调用形式
// 普通函数
int add(int i, int j) { return i + j; }
// lambda 产生一个未命名的函数对象类
auto mod = [] (int i, int j) { return i % j; };
// 函数对象类
struct divide {
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};

// 同一种形式：
int (int, int)

// 函数表(function table)
// 构建从运算符到函数指针的映射关系，其中函数接受2个int，返回一个int
map<string, int(*)(int, int)> binops;

// 正确：add是一个指向正确函数类型的指针
binops.insert({"+", add});
// 但我们不能将mod或者divide存入binops
binops.insert({"%", mod});  // 错误：mod不是一个函数指针

// 标准库function类型

function<int(int, int)> f1 = add;   // 函数指针
function<int(int, int)> f2 = divide();  // 函数对象类的对象
function<int(int, int)> f3 = [] (int i, int j) { return i * j; }; // lambda
cout << f1(4, 2) << endl;
cout << f2(4, 2) << endl;
cout << f3(4, 2) << endl;

// 重新定义map
map<string, function<int(int, int)>> binops;
map<string, function<int(int, int)>> binops = {
    {"+", add},     // 函数指针
    {"-", std::minus<int>()},   // 标准库函数对象
    {"/", divide()},    // 用户定义的函数对象
    {"*", [] (int i, int j) { return i * j; }},     //未命名的lambda
    {"%", mod}  // 命名了的lambda
};

binops["+"](10, 5); // 调用add(10, 5)
binops["-"](10, 5); // 使用minus<int>对象的调用运算符
binops["/"](10, 5); // 使用divide对象的调用运算符
binops["*"](10, 5); // 调用lambda函数对象
binops["%"](10, 5); // 调用lambda函数对象


// 不能（直接）将重载函数的名字存入function类型的对象中
int add(int i, int j) { return i + j; }
Sales_data add(const Sales_data&, const Sales_data&);
map<string, function<int(int, int)>> binops;
binops.insert({"+", add});  // 错误：哪个add？

// 解决二义性问题一条途径是存储函数指针，而非函数的名字
int (*fp)(int, int) = add;  // 指针所指的add是接受2个int的版本
binops.insert({"+", fp});   // 正确：fp指向一个正确的add版本

// 同样，也能使用lambda来消除二义性
// 正确：使用lambda来指定我们希望使用的add版本
binops.insert("+", [] (int a, int b) { return add(a, b); });

