#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct compare {
    bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (const string& word : words) {
        m[word]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> q;
    for (auto& word_count : m) {
        q.push(word_count);
        if (q.size() > k) {
            q.pop();
        }
    }

    vector<string> res(k);
    for (int i = k - 1; i >= 0; --i) {
        res[i] = q.top().first;
        q.pop();
    }
    return res;
}

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> res;
    res = topKFrequent(words, 1);
    for (const string& w : res) {
        cout << w << " ";
    }
}


vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (const string& word : words) {
        m[word]++;
    }

    auto cmp = [] (const pair<string, int>& a, const pair<string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
    for (const auto& word_count : m) {
        q.push(word_count);
        if (q.size() > k) {
            q.pop();
        }
    }

    vector<string> res(k);
    for (int i = k - 1; i >= 0; --i) {
        res[i] = q.top().first;
        q.pop();
    }
    return res;
}