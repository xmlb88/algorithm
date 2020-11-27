#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ³¬Ê±
unordered_map<string, vector<bool>> memo;
int countEval(string s, int result) {
    vector<bool> res = dfs(s);
    int count = 0;
    for (auto b : res) {
        if (b == result) count++;
    }
    return count;
}

vector<bool> dfs(string s) {
    if (memo.count(s)) return memo[s];
    vector<bool> res;
    if (s.length() == 1) {
        if (s == "1") res.push_back(1);
        else res.push_back(0);

        memo[s] = res;
        return res;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '&' || s[i] == '|' || s[i] == '^'){
            vector<bool> left = dfs(s.substr(0, i));
            vector<bool> right = dfs(s.substr(i + 1));

            for (auto a : left) {
                for (auto b : right) {
                    if (s[i] == '&') res.push_back(a & b);
                    else if (s[i] == '|') res.push_back(a | b);
                    else if (s[i] == '^') res.push_back(a ^ b);
                }
            }
        }
    }

    memo[s] = res;  
    return memo[s];
}

// 
unordered_map<string, int> memo;
int countEval(string s, int result) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return stringToBool(s) == result ? 1 : 0;
    if (memo.count(s + to_string(result))) return memo[s + to_string(result)];

    int ways = 0;
    for (int i = 1; i < s.length(); i += 2) {
        char c = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        int leftTrue = countEval(left, true);
        int leftFalse = countEval(left, false);
        int rightTrue = countEval(right, true);
        int rightFalse = countEval(right, false);

        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);
        int totalTrue = 0;
        if (c == '^') {
            totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
        } else if (c == '&') {
            totalTrue = leftTrue * rightTrue;
        } else if (c == '|') {
            totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
        }

        int subways = result ? totalTrue : total - totalTrue;
        ways += subways;
    }

    memo[s + to_string(result)] = ways;
    return ways;
}

bool stringToBool(string c) {
    return c == "1" ? true : false;
}