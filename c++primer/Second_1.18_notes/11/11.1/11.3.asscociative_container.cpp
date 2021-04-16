#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
using namespace std;


/* 
key_type
mapped_type
value_type
 */

set<string>::value_type v1;
set<string>::key_type v2;
map<string, int>::value_type v3;
map<string, int>::key_type v4;
map<string, int>::mapped_type v5;

int main() {
    map<string, int> word_count = {{"xmlb", 1}};
    auto map_it = word_count.begin();
    cout << map_it -> first;
    cout << " " << map_it -> second;
    // 关键字是const的，不能改变值
    // map_it -> first = "new key";
    ++map_it -> second;
    cout << endl << map_it -> first;
    cout << " " << map_it -> second << endl;

    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end()) {
        // 错误
        // *set_it = 42
        cout << *set_it << endl;
    }

}

// 迭代器遍历
void print_word_count(map<string, int> word_count) {
    auto map_it = word_count.begin();
    while (map_it != word_count.end()) {
        cout << map_it -> first << " occurs "
            << map_it -> second << " times" << endl;
        ++map_it;
    }
}

// 