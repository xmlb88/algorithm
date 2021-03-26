#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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