#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // in   读方式  (ifstream, fstream)
    // out  写方式  (ofstream, fstream) 
    //(默认没有指定trunc，文件也会截断，保留文件内容指定app；或者同时指定in模式)
    // app  每次写操作前均定位到文件末尾 (trunc没被设定，可以不显示out也以out模式打开)
    // ate  打开文件后立即定位到文件末尾
    // trunc    截断文件 (out)
    // binary   以二进制方式进行IO
    // ate 和 binary模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用

    // file1被截断
    ofstream out("file1");  // 隐含以输出模式打开文件并截断文件
    ofstream out2("file1", ofstream::out);  // 隐含截断文件
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    // 为了保留文件内容，必须显示指定app模式
    ofstream app("file2", ofstream::app); //隐含输出模式
    ofstream app2("file2", ofstream::out | ofstream::app);


    ofstream out;   // 未指定文件打开模式
    out.open("scratchpad"); // 模式模式隐含为输出和截断
    out.close();
    out.open("precious", ofstream::app);    //输出模式为追加
    out.close();
}