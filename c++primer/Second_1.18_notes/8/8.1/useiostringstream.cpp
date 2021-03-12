#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

// 先定义一个类来描述输入数据
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char **argv) {
    string file_name = argv[1];
    ifstream ifs(file_name);
    string line, word;  // 来自输入的一行和单词
    vector<PersonInfo> people;  // 保存来自输入的所有记录
    // 逐行从输入读取数据，直至cin遇到文件末尾(或其他错误)
    while (getline(ifs, line)) {
        PersonInfo info;    //创建一个保存次记录数据的对象
        istringstream record(line); //将记录绑定到刚读入的行
        record >> info.name;    // 读取名字
        while (record >> word) {    // 读取电话号码
            info.phones.push_back(word);    // 保持它们
        }
        people.push_back(info); // 将此记录追加到people末尾
    }

    // use ostringstream

    ofstream os, oerr;
    os.open("rPhone", ofstream::app);
    oerr.open("bPhone", ofstream::app);
    
    for (const auto& entry : people) {  //对people中的每一项
        ostringstream formatted, badNums;   // 每个循环步创建的对象
        for (const auto& nums : entry.phones) {
            if (nums.size() != 10) {
                badNums << " " << nums; // 将数的字符串形式存入badNums
            } else {
                formatted << " " << nums;
            }
        }

        if (badNums.str().empty()) { // 没有错误的数
            os << entry.name << " " 
               << formatted.str() << endl;
        } else {
            oerr << "input error: " << entry.name 
                 << " invalid numbers(s) " << badNums.str() << endl;
        }
    }
}