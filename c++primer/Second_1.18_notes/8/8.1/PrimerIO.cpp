#include <iostream>
#include <string>
using namespace std;

int main() {
    // string s;
    // cin >> s;
    // cout << s << endl;
    // cout << cin.good() << endl;
    // cout << cin.rdstate() << endl;

    // auto old_state = cin.rdstate()  // 记住cin的当前状态
    // cin.clear();                    // 使cin有效
    // process_input(cin);             // 使用cin
    // cin.setstate(old_state);        // 将cin置为原有状态

    // cout << "hi!" << endl;  // 输出hi和一个换行，然后刷新缓冲区
    // cout << "hi!" << flush; // 输出hi，然后刷新缓冲区，不附加任何额外字符
    // cout << "hi!" << ends;  // 输出hi和一个空字符，然后刷新缓冲区
    // cout << "hi";

    cout << unitbuf; // 所有输出操作后都会立即刷新缓冲区
    // 任何输出都立即刷新，无缓冲
    cout << nounitbuf;  // 回到正常的缓冲方式
    // 如果程序崩溃，输出缓冲区不会被刷新

    // 关联输入和输出流

    // 282
    cin.tie(&cout); // 仅展示：标准库将cin和cout关联在一起
    // old_tie指向当前关联到cin的流（如果有的话）
    ostream *old_tie = cin.tie(nullptr);
    *old_tie << "tie success" << endl;  // cin不再与其他流关联
    // 将cin与cerr关联，not a good idea，因为cin应该关联到cout
    cin.tie(&cerr); // 读取cin会刷新cerr而不是cout
    cin.tie(old_tie);   // 重建cin和cout间的正常关联
}