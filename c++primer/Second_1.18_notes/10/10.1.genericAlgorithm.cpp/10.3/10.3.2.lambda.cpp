#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimsDups(words);   // 将words按字典序排序，删除重复单词
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), isShorter);
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    // 计算满足size >= sz元素的数目
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格

}

// find_if()：接受一对迭代器，表示一个范围，第三个参数是一个谓词
// find_if()算法对输入序列中的每个元素调用给定的这个谓词，返回第一个使谓词返回非0值的元素，如果不存在这样的元素，返回尾后迭代器


// lambda表达式：可调用的代码单元，理解：未命名的内联函数
// 具有一个返回类型，一个参数列表和一个函数体，与函数不同，lambda可能定义在函数内部
// [capture list] (parameter list) -> return type {function body}
// capture list(捕获列表):是一个lambda所在函数中定义的局部变量的列表，通常为空
// 其余与普通函数一样
// 与普通函数不同的是，lambda必须使用尾置返回
// 可忽略参数列表和返回类型，但必须永远包含捕获列表和函数体
auto f = [] {return 42;};
// 与普通函数一样使用调用运算符()
cout << f() << endl;
// int main() {
//     cout << f() << endl;
// }

/* 
忽略括号和参数列表等价于指定一个空参数列表
忽略返回类型，lambda根据函数体中的代码推断出返回类型，
如果函数体只是一个return语句，则返回类型从返回的表达式的类型推断而来，否则返回类型为void
 */

// 与isShorter函数相同的lambda
[] (const string& a, const string& b) {
    return a.size() < b.size();
}
/* 
空捕获列表：此lambda不使用它所在函数中的任何局部变量
 */

stable_sort(words.begin(), words.end(), [] (const string& a, const string& b)
{return a.size() < b.size();});


// 使用捕获列表
void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimsDups(words);   // 将words按字典序排序，删除重复单词
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), isShorter);
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    // 计算满足size >= sz元素的数目
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格

    [sz] (const string& a) {return a.size() >= sz;};
    // 调用find_if
    auto wc = find_if(words.begin(), words.end(), [sz] (const string& a) {
        return a.size() >= sz;
    });

    // 用find_if返回的迭代器计算从它开始到words的末尾一共有多少个元素
    auto count = words.end() - wc;

    // for_each打印
    for_each(wc, words.end(), [] (const string& s){
        cout << s << " ";
    });
}

/* 
lambda捕获和返回
值捕获：
与传值参数类似，采用值捕获的前提是变量可以拷贝
与参数不同，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝
 */

void fcn1() {
    size_t v1 = 42; // 局部变量
    // 将v1拷贝到名为f的可调用对象
    auto f = [v1] {return v1;};
    v1 = 0;
    auto j = f(); // j为42，f保存了我们创建它时v1的拷贝
}

/* 
引用捕获
 */

void fcn2() {
    size_t v1 = 42;
    auto f2 = [&v1] {return v1;};
    v1 = 0;
    auto j = f2(); // j为0，f2保存v1的引用
}

// 351
// 引用捕获用来输出数据，并接受一个字符作为分隔
void biggies(vector<string>& words, vector<string>::size_type sz, ostream& os = cout, char c = ' ') {
    // 与之前的例子一样重排words的代码
    // 打印count的语句改为打印到os
    for_each(words.begin(), words.end(), [&os, c] (const string& s){
        os << s << c;
    });
}

// 隐式捕获
// 隐式值捕获
wc = find_if(words.begin(), words.end(), [=] (const string& s) {
    return s.size() >= sz;
});

// 如果一部分采用值捕获，其他变量采用引用捕获，可以混合使用隐式捕获和显示捕获
void biggies(vector<string>& words, vector<string>::size_type sz, ostream& os = cout, char c = ' ') {
    // 其他处理与之前一样
    // os隐式捕获，引用捕获方式；c显示捕获，值捕获方式
    for_each(words.begin(), words.end(), [&, c] (const string& s) {
        os << s << c;
    });

    // os显示捕获，引用捕获方式；c隐式捕获，值捕获方式
    for_each(words.begin(), words.end(), [=, &os] (const string& s) {
        os << s << c;
    });
}

// 混用隐式捕获和显示捕获时，捕获列表中第一个元素必须是一个&或=，此符号指定了默认捕获方式为引用或值
// 混用时，显示捕获的变量必须使用与隐式捕获不同的方式


// 可变lambda：
void fcn3() {
    size_t v1 = 42; // 局部变量
    // f可以改变它所捕获的变量的值
    auto f = [v1] () mutable {return ++v1;};
    v1 = 0;
    auto j = f();   // j 为43
}

// 一个引用捕获的变量是否可以修改依赖于此引用指向的是一个const类型还是一个非const类型
void fcn4() {
    size_t v1 = 42; // 局部变量
    // v1是一个非const变量的引用
    // 可以通过f2中的引用来改变它
    auto f2 = [&v1] {return ++v1;};
    v1 = 0;
    auto j = f2(); // j为1
}

// 指定lambda返回类型
// 例子：使用标准库transform算法和一个lambda将序列中的每个负数替换为其绝对值
transform(vi.begin(), vi.end(), v1.begin(), [] (int i) {
    return i < 0 ? -i : i;
});

// 错误：不能推断lambda的返回类型
transform(vi.begin(), vi.end(), vi.begin(), [] (int i) {
    if (i < 0) return -i;
    else return i;
});
// 编译器推断这个版本的lambda返回类型为void，但它返回了一个int值
// 当需要为一个lambda定义返回类型时，必须使用尾置返回类型
transform(vi.begin(), vi.end(), vi.begin(), [] (int i) -> int {
    if (i < 0) return -i;
    else return i;
});


// 10.3.4 参数绑定

// 对于捕获局部变量的lambda，用函数来替换它不是那么容易
// find_if调用lambda来比较一个string和一个给定大小，编写函数：
bool check_size(const string& s, string::size_type sz) {
    return s.size() >= sz;
}
// 但是，我们不能用这个函数作为find_if的一个参数，find_if接受一个一元谓词，
// 传递给find_if的可调用对象必须接受单一参数
// 参数个数：一元谓词，二元谓词  


// 解决向check_size传递一个长度参数的问题
// bind 头文件#include <functional>
auto newCallable = bind(callable, arg_list);

auto check6 = bind(check_size, _1, 6);

auto wc = fidn_if(words.begin(), words.end(), [sz] (const string& a));
// 可替换为如下版本

auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));

// placeholders
using std::placeholders::_1;
using namespace std::placeholders;

// g是一个有2个参数的可调用对象
auto g = bind(f, a, b, _2, c, _1);

// 用bind重排参数排序
// 按单词长度由短至长排序
sort(words.begin(), words.end(), isShorter);
// 按单词长度由长至短排序
sort(words.begin(), words.end(), bind(isShorter, _2, _1));

// 绑定引用参数
// 例如：替换一个引用方式捕获ostream的lambda：
// os是一个局部变量，引用一个输出流
// c是一个局部变量，类型为char
for_each(words.begin(), words.end(), [&os, c] (const string& s) {
    os << s << c;
});

// 编写函数，完成相同的工作
ostream& print(ostream& os, const string& s, char c) {
    return os << s << c;
}

// 但是，不能直接用bind代替对os的捕获
// 错误：不能拷贝os
for_each(words.begin(), words.end(), bind(print, os, _1, ' '));

// 使用ref
for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
// ref返回一个对象，包含给定的引用，cref保存const 引用的类


