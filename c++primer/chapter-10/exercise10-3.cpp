#include <iostream>
using namespace std;



// ʹ�ò����б�
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
