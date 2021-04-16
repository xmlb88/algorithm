#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <utility> // pair
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

// int main() {
//     count_word_filter();
// }


//初始化
// map<string, size_t> word_count; // 空容器
set<string> exclude;
map<string, string> authors = {
    {"Joyce", "James"},
    {"Austen", "Jane"},
    {"Dickens", "Charles"}
};

// map, set关键字唯一
void _test() {
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);  // 每个数重复保存一次
    }
    // iset包含来自ivec的不重复的元素；miset包含所有20个元素
    set<int> iset(ivec.begin(), ivec.end());
    multiset<int> miset(ivec.begin(), ivec.end());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}

// int main() {
//     _test();
// }

// strict weak ordering

bool compareIsbn(const Sales_date& lhs, const Sales_date& rhs) {
    return lhs.isbn() < rhs.isbn();
}

// 定义multiset时提供2个类型：关键字类型Sales_date,以及比较操作类型
// 函数指针类型，指向compareIsbn
// bookstore中多条记录可以有相同的ISBN
// bookstore中的元素以ISBN的顺序进行排序
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
map<string, list<int>> m;
using Less = bool (*) (Sales_data const&, Sales_data const&);
multiset<Sales_data, Less> bookstore(less);

pair<string, string> anon;
pair<string, size_t> word_count;
pair<string, vector<int>> line;

// 初始化器
pair<string, string> author{"James", "Joyce"};
// 380

int main() {
    cout << author.first << " " << author.second << endl;
}
