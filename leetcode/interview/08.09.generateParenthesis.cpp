#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<string> generateParenthesis(int n) {
    string str;
    dfs(n, n, str);
    return res;
}

void dfs(int left, int right, string str) {
    if (left == 0 && right == 0) {
        res.push_back(str);
        return;
    }

    if (left > 0) {
        str.push_back('(');
        dfs(left - 1, right, str);
        str.pop_back();
    }

    if (right > 0 && right > left) {
        str.push_back(')');
        dfs(left, right - 1, str);
        str.pop_back();
    }
}

// review
vector<string> generateParenthesis(int n) {
    if (n == 0) return {};
    vector<string> res;
    string track;
    backtrack(n, n, track, res);
    return res;
}

void backtrack(int left, int right, string& track, vector<string>& res) {
    if (right < left) return;
    if (left < 0 || right < 0) return;
    if (left == 0 && right == 0) {
        res.push_back(track);
        return;
    }

    track.push_back('(');
    backtrack(left - 1, right, track, res);
    track.pop_back();

    track.push_back(')');
    backtrack(left, right - 1, track, res);
    track.pop_back();
}