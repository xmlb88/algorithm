#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumSwap(int num) {
    string s = to_string(num);
    int max_num = num;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            max_num = max(max_num, stoi(afterSwap(s, i, j)));
        }
    }
    return max_num;
}

string afterSwap(string s, int i, int j) {
    swap(s[i], s[j]);
    return s;
}

// 贪心
int maximumSwap(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.size() - 1; ++i) {
        int index = -1;
        char max_number = '0';
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[j] >= max_number) {
                index = j;
                max_number = s[j];
            }
        }
        if (index != -1 && max_number > s[i]) {
            swap(s[i], s[index]);
            return stoi(s);
        }
    }
    return num;
}

// 优化，2次遍历
int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.size();
    vector<int> right_max_index(n);

    int index = n - 1;
    char max_number = s[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (s[i] > max_number) {
            max_number = s[i];
            index = i;
        }
        right_max_index[i - 1] = index;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[right_max_index[i]] > s[i]) {
            swap(s[right_max_index[i]], s[i]);
            return stoi(s);
        }
    }
    return num;
}