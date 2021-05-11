#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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