#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<string> permutation(string s) {
    string t;

}

void dfs(string s, string& t) {
    if (t.size() == s.size()) {
        res.push_back(t);
        return;
    }

    for (int i = 0, i < s.size(); i++) {
        if (s.find(s[i]) == )
    }
}