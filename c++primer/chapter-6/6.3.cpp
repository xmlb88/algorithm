#include <iostream>
#include <string>
using namespace std;

char &get_val(string &str, string::size_type ix) {
    return str[ix];
}

int main() {
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;
    return 0;
}

string (&func(string))[10]

typedef string str_arr[10];
str_arr& func()

using str_arr = string[10]
str_arr& func()

auto func() -> string(&)[10]

string s[10];
decltype(s) &func();