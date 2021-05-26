#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// ���ʼ���
void unordered_word_count() {
    unordered_map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        ++word_count[word]; // ��ȡ������word�ļ�����
    }
    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    }
}

// 395