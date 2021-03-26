#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// �������ɶ���������
vector<string> words;
sort(words.begin(), words.end(), isShorter);
// �����㷨

// �������������򣬳�����ͬ�ĵ���ά���ֵ���
stable_sort(words.begin(), words.end(), isShorter);
for (const auto & s : words) {
    cout << s << " ";
}
cout << endl;