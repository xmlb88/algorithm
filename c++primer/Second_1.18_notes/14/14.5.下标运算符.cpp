#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 下标运算符必须是成员函数
// example
class StrVec {
public:
    std::string& operator[](std::size_t n) {
        return elements[n];
    }
    const std::string& operator[](std::size_t n) const {
        return elements[n];
    }
private:
    std::string *elements;  // 指向数组首元素的指针
}

// 假设svec是一个StrVec对象
const StrVec cvec = svec;   // 把svec的元素拷贝到cvec中
// 如果svec中含有元素，对第一个元素运行string的empty函数
if (svec.size() && svec[0].empty()) {
    svec[0] = "zero";   // 正确：下标运算符返回string的引用
    cvec[0] = "zip";    // 错误：对cvec取下标返回的是常量引用
}

