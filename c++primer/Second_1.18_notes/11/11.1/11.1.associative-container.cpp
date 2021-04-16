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
// �ظ�
// ˳��/����
// �ظ���multi
// ����unordered
// unordered_multi_set:�����ظ��ؼ��֣�Ԫ������ļ���

// ���ʼ���
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


//��ʼ��
// map<string, size_t> word_count; // ������
set<string> exclude;
map<string, string> authors = {
    {"Joyce", "James"},
    {"Austen", "Jane"},
    {"Dickens", "Charles"}
};

// map, set�ؼ���Ψһ
void _test() {
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);  // ÿ�����ظ�����һ��
    }
    // iset��������ivec�Ĳ��ظ���Ԫ�أ�miset��������20��Ԫ��
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

// ����multisetʱ�ṩ2�����ͣ��ؼ�������Sales_date,�Լ��Ƚϲ�������
// ����ָ�����ͣ�ָ��compareIsbn
// bookstore�ж�����¼��������ͬ��ISBN
// bookstore�е�Ԫ����ISBN��˳���������
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
map<string, list<int>> m;
using Less = bool (*) (Sales_data const&, Sales_data const&);
multiset<Sales_data, Less> bookstore(less);

pair<string, string> anon;
pair<string, size_t> word_count;
pair<string, vector<int>> line;

// ��ʼ����
pair<string, string> author{"James", "Joyce"};
// 380

int main() {
    cout << author.first << " " << author.second << endl;
}
