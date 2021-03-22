#include <iostream>
#include <string>
using namespace std;

int main() {
    // 每步循环查找name中下一个数
    string numbers("0123456789"), name("r2d2abcd1ef6ghi7");
    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << "element is: " << name[pos] << endl;
        ++pos;
    }

    string river("Mississippi");
    auto first_pos = river.find("is"); // 返回1
    auto last_pos = river.rfind("is"); // 返回4
    cout << "first_pos: " << first_pos << " last_pos: " << last_pos << endl;
    auto last_not_of = river.find_last_not_of("is");
    cout << "find_last_not_of: " << last_not_of << endl;

    cout << river.compare(numbers) << endl;
}