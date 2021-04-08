#include <iostream>
#include <string>
using namespace std;

string line = "apple,this";
auto comma = find(line.cbegin(), line.cend(), ',');
cout << string(line.cbegin(), comma) << endl;

// 打印最后一个单词
auto rcomma = find(line.crbegin(), line.crend(), ',');
// 错误：将逆序输出单词的字符
cout << string(line.crbegin(), rcomma) << endl;
// FIRST,MIDDLE,LAST
// 输出：TSAL
// reverse_iterator的base成员，转换返回其对应的普通迭代器
// 正确的方式
cout << string(rcomma.base(), line.cend()) << endl;
// 打印LAST
