#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string S) {
    int i = 0, j;
    int last;
    vector<int> res;
    unordered_set<char> contain;
    while (i < S.size()) {
        char c = S[i];
        contain.insert(c);
        j = S.size() - 1;
        while (S[j] != c) j--;
        last = j;
        
        int k = i + 1;
        while (k < last) {
            if (contain.count(S[k])) {
                k++;
                continue;
            }
            else {
                j = S.size() - 1;
                while (S[j] != S[k]) j--;
                if (j > last) {
                    last = j;
                }
                contain.insert(S[k]);
                k++;
            }
        }
        res.push_back(last - i + 1);
        i = last + 1;
    }
    return res;
}

vector<int> partitionLabels(string S) {
    int n = S.size();
    unordered_map<char, int> last_position;
    for (int i = 0; i < n; i++) {
        last_position[S[i]] = i;
    }
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        end = max(end, last_position[S[i]]);
        if (i == end) {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}