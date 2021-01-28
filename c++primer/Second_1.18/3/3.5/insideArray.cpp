#include <iostream>
#include <iterator>
#include <cstring>
#include <string>
using namespace std;

int main() {
    // char a1[] = {'c', '+', 'd', '\0'};
    // for (int i = 0; i < 4; i++) {
    //     cout << a1[i] << " ";
    // }
    

    // const char a4[7] = "Daniel";
    // for (int i = 0; i < 7; i++) {
    //     cout << a4[i] << "/";
    // }

    constexpr size_t sz = 5;
    int arr[sz] = {1, 2, 3, 4, 5};
    auto n = end(arr) - begin(arr);
    cout << n << endl;
    int *b = arr, *e = arr + sz;
    while (b < e) {
        cout << *b << endl;
        ++b;
    }
    cout << endl;

    char ca[] = {'c', '+', '+'};
    cout << strlen(ca) << endl;
    cout << endl;

    char c1[] = "abcdef";
    char c2[] = "abcde";
    cout << strcmp(c1, c2) << endl;
    cout << endl;

    const char cb[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = cb;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
    cout << endl;

    // use string
    string s1("Mooophy"), s2("Pezy");
    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "Mooophy > Pezy" << endl;
    else
        cout << "Pezy > Mooophy" << endl;
    cout << "==================" << endl;

    // use c-style character strings
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";
    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "Wangyue < Pezy" << endl;
    else
        cout << "Wangyue > Pezy" << endl;
    cout << "==================" << endl;

    
}