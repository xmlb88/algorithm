#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// set/map
// 重复
// 顺序/无序
// 重复：multi
// 无序：unordered
// unordered_multi_set:允许重复关键字，元素无序的集合

// 单词计数
void count_word() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;
    }
}

void count_word_filter() {
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }
    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;
    }
}

int main() {
    count_word_filter();
}