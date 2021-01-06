#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// unordered_map<char, vector<char>> m;
unordered_map<char, string> m{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
vector<string> res;
string letters;
vector<string> letterCombinations(string digits) {
    // m['2'] = {'a', 'b', 'c'};
    // m['3'] = {'d', 'e', 'f'};
    // m['4'] = {'g', 'h', 'i'};
    // m['5'] = {'j', 'k', 'l'};
    // m['6'] = {'m', 'n', 'o'};
    // m['7'] = {'p', 'q', 'r', 's'};
    // m['8'] = {'t', 'u', 'v'};
    // m['9'] = {'w', 'x', 'y', 'z'};

    int n = digits.size();
    if (n == 0) return {};
    dfs(digits, 0);
    return res;
}

void dfs(string& digits, int index) {
    if (index == digits.size()) {
        res.push_back(letters);
        return;
    }

    for (char c : m[digits[index]]) {
        letters.push_back(c);
        dfs(digits, index + 1);
        letters.pop_back();
    }
}