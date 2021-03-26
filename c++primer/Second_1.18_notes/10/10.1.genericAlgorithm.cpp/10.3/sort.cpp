#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// 按长度由短至长排序
vector<string> words;
sort(words.begin(), words.end(), isShorter);
// 排序算法

// 按长度重新排序，长度相同的单词维持字典序
stable_sort(words.begin(), words.end(), isShorter);
for (const auto & s : words) {
    cout << s << " ";
}
cout << endl;