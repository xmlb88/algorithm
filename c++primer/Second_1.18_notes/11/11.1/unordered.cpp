#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// 单词计数
void unordered_word_count() {
    unordered_map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        ++word_count[word]; // 提取并递增word的计数器
    }
    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    }
}

// 395