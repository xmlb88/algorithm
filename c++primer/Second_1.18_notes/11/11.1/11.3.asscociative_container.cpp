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

// 添加元素
/* 
word_count.insert({word, 1});
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, int> (word, 1));
word_count.insert(map<string, int>::value_type (word, 1));
 */

/* 
c.insert(v)
c.emplace(args)
c.insert(b, e)
c.insert(il)
c.insert(p, v)
c.emplace(p, args)
 */

// insert返回值：返回pair，fisrt是迭代器，指向具有给定关键字的元素
// second成员bool值，指出元素是插入成功还是已经存在于容器中
// 如果已在容器中，bool为false，不存在则被插入容器中，bool为true

// 例：统计每个单词在输入中出现次数的一种更繁琐的方法
void word_count_temp_3() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first -> second;
    }
    // 旧版本
    // pair<map<string, size_t>::iterator, bool> ret = 
    //      word_count.insert(make_pair(word, 1));

    // multimap, multiset总会插入一个元素
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    // 返回指向新元素的迭代器
}

// 11.20
void word_count_iterator() {
    map<string, size_t> counts;
    for (string word; cin >> word;) {
        auto result = counts.insert({word, 1});
        if (!result.second) {
            ++result.first -> second;
        }
    }

    for (auto const& count : counts) {
        cout << count.first << " " << count.second << ((count.second > 1) ? "times\n" : "time\n");
    }
}

// 11.21
void word_count_practice() {
    map<string, int> word_count;
    while (cin >> word) {
        ++word_count.insert({word, 1}).first -> second;
    }

    // equals:
    while (cin >> word) {
        auto result = word_count.insert({word, 0});
        ++result.first -> second;
    }
}

// 11.22
void string_vector() {
    map<string, vector<int>> mp;
    pair<string, vector<int>>; // 参数类型
    pair<map<string, vector<int>>::iterator, bool>; // 返回类型
}


// 11.23
void map_children() {
    multimap<string, string> families;
    for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
    for (auto const& family : families) {
        cout << family.second << " " << family.first << endl;
    }
}

// 11.3.3删除元素
// erase 1.迭代器， 2.迭代器对， 3.key_type
void erase_by_key_type(string removal_word) {
    map<string, size_t> word_count;
    if (word_count.erase(removal_word)) {
        cout << "ok: " << removal_word << " removed\n";
    }
    else cout << "oops: " << removal_word << " not found!\n";
}
// 不重复关键字的容器，总是返回0或者1,
// c.erase(k)
// c.erase(p)
// c.erase(b, e)

// map和unordered_map容器提供下标运算符和对应的at函数
// set, multimap, unordered_multimap不能用下标

// attention:
// 如果关键字并不在map中，会为它创建一个元素并插入到map中，关联值将进行值初始化
void at_map() {
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
}

/* 
将会执行如下操作：
    在word_count中搜索关键字为Anna的元素，未找到
    将一个新的关键字-值对插入到word_count中，关键字是一个const string，保存Anna，值进行值初始化，在本例中意味着值为0
    提取出新插入的元素，并将值1赋予它
 */

// c[k]：返回关键字为k的元素，如果k不在c中，添加一个关键字为c的元素，对其进行值初始化
// c.at[k]：访问关键字为k的元素，带参数检查，若k不在c中，抛出一个out_of_range异常
// 387

// 11.3.5访问元素

/* 
// lower_bound 和 upper_bound不适用于无序容器
// 下标和at只适用于非const的map和unordered_map
c.find(k) // 返回迭代器指向关键字为k的元素，若k不在容器中，返回尾后迭代器
c.count(k)
c.lower_bound(k)
c.upper_bound(k)
c.equal_range(k) 返回迭代器pair , pair<map<string, int>::iterator, map<string, int>::iterator> 表示等于k的范围
若k不存在，pair的2个成员为c.end()
 */


void user_find_not_at() {
    map<string, size_t> word_count;
    if (word_count.find("foobar") == word_count.end()) {
        cout << "foobar is not in the map" << endl;
    }
}


// 在multimap或multiset中查找元素
void serach1(multimap<string, string>& authors) {
    string search_item("Alain de Botton");
    auto entries = authors.count(search_item); // 数量
    auto iter = authors.find(search_item);  // 第一本书
    // 用一个循环查找
    while (entries) {
        cout << iter -> second << endl;
        ++iter; // 前进到下一本书
        --entries;
    }
}

// 面向迭代器的解决方法
void search2(multimap<string, string>& authors, string search_item) {
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg) {
        cout << beg -> second << endl;
    }
}

// 适用equeal_range
void search3(multimap<string, string>& authors, string search_item) {
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first) {
        cout << pos.first -> second << endl;
    }
}

// 11.28:map<string, vector<int>>::iterator
// 不改变顺序的iterator，make_pair(c.end(). c.end())

