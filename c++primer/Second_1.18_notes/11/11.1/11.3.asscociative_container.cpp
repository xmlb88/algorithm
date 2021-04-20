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
    // �ؼ�����const�ģ����ܸı�ֵ
    // map_it -> first = "new key";
    ++map_it -> second;
    cout << endl << map_it -> first;
    cout << " " << map_it -> second << endl;

    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end()) {
        // ����
        // *set_it = 42
        cout << *set_it << endl;
    }

}

// ����������
void print_word_count(map<string, int> word_count) {
    auto map_it = word_count.begin();
    while (map_it != word_count.end()) {
        cout << map_it -> first << " occurs "
            << map_it -> second << " times" << endl;
        ++map_it;
    }
}

// ���Ԫ��
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

// insert����ֵ������pair��fisrt�ǵ�������ָ����и����ؼ��ֵ�Ԫ��
// second��Աboolֵ��ָ��Ԫ���ǲ���ɹ������Ѿ�������������
// ������������У�boolΪfalse���������򱻲��������У�boolΪtrue

// ����ͳ��ÿ�������������г��ִ�����һ�ָ������ķ���
void word_count_temp_3() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first -> second;
    }
    // �ɰ汾
    // pair<map<string, size_t>::iterator, bool> ret = 
    //      word_count.insert(make_pair(word, 1));

    // multimap, multiset�ܻ����һ��Ԫ��
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    // ����ָ����Ԫ�صĵ�����
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
    pair<string, vector<int>>; // ��������
    pair<map<string, vector<int>>::iterator, bool>; // ��������
}


// 11.23
void map_children() {
    multimap<string, string> families;
    for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
    for (auto const& family : families) {
        cout << family.second << " " << family.first << endl;
    }
}

// 11.3.3ɾ��Ԫ��
// erase 1.�������� 2.�������ԣ� 3.key_type
void erase_by_key_type(string removal_word) {
    map<string, size_t> word_count;
    if (word_count.erase(removal_word)) {
        cout << "ok: " << removal_word << " removed\n";
    }
    else cout << "oops: " << removal_word << " not found!\n";
}
// ���ظ��ؼ��ֵ����������Ƿ���0����1,
// c.erase(k)
// c.erase(p)
// c.erase(b, e)

// map��unordered_map�����ṩ�±�������Ͷ�Ӧ��at����
// set, multimap, unordered_multimap�������±�

// attention:
// ����ؼ��ֲ�����map�У���Ϊ������һ��Ԫ�ز����뵽map�У�����ֵ������ֵ��ʼ��
void at_map() {
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
}

/* 
����ִ�����²�����
    ��word_count�������ؼ���ΪAnna��Ԫ�أ�δ�ҵ�
    ��һ���µĹؼ���-ֵ�Բ��뵽word_count�У��ؼ�����һ��const string������Anna��ֵ����ֵ��ʼ�����ڱ�������ζ��ֵΪ0
    ��ȡ���²����Ԫ�أ�����ֵ1������
 */

// c[k]�����عؼ���Ϊk��Ԫ�أ����k����c�У����һ���ؼ���Ϊc��Ԫ�أ��������ֵ��ʼ��
// c.at[k]�����ʹؼ���Ϊk��Ԫ�أ���������飬��k����c�У��׳�һ��out_of_range�쳣
// 387

// 11.3.5����Ԫ��

/* 
// lower_bound �� upper_bound����������������
// �±��atֻ�����ڷ�const��map��unordered_map
c.find(k) // ���ص�����ָ��ؼ���Ϊk��Ԫ�أ���k���������У�����β�������
c.count(k)
c.lower_bound(k)
c.upper_bound(k)
c.equal_range(k) ���ص�����pair , pair<map<string, int>::iterator, map<string, int>::iterator> ��ʾ����k�ķ�Χ
��k�����ڣ�pair��2����ԱΪc.end()
 */


void user_find_not_at() {
    map<string, size_t> word_count;
    if (word_count.find("foobar") == word_count.end()) {
        cout << "foobar is not in the map" << endl;
    }
}


// ��multimap��multiset�в���Ԫ��
void serach1(multimap<string, string>& authors) {
    string search_item("Alain de Botton");
    auto entries = authors.count(search_item); // ����
    auto iter = authors.find(search_item);  // ��һ����
    // ��һ��ѭ������
    while (entries) {
        cout << iter -> second << endl;
        ++iter; // ǰ������һ����
        --entries;
    }
}

// ����������Ľ������
void search2(multimap<string, string>& authors, string search_item) {
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg) {
        cout << beg -> second << endl;
    }
}

// ����equeal_range
void search3(multimap<string, string>& authors, string search_item) {
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first) {
        cout << pos.first -> second << endl;
    }
}

// 11.28:map<string, vector<int>>::iterator
// ���ı�˳���iterator��make_pair(c.end(). c.end())

