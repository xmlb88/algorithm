#include <iostream>
using namespace std;



// 使用捕获列表
// auto wc = find_if(words.begin(), words.end(), 
//             [sz](const string& a){
//                 return a.size() >= sz;
//             });

int main() {
    int grade = 55;
    cout << ((grade < 60) ? "fail" : "pass");
    cout << (grade < 60) ? "fail" : "pass";
    cout << grade < 60 ? "fail" : "pass";
}
