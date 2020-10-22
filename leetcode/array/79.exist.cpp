#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// 深度优先搜索，回溯
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w) {
    if (board[i][j] != word[w]) return false;
    if (w == word.size() - 1) return true;
    board[i][j] = '0';
    if ((i + 1 < board.size() && dfs(board, word, i + 1, j, w + 1))
    || (i - 1 >= 0 && dfs(board, word, i - 1, j, w + 1))
    || (j + 1 < board[0].size() && dfs(board, word, i, j + 1, w + 1))
    || (j - 1 >= 0 && dfs(board, word, i, j - 1, w + 1))
    ) return true;
    board[i][j] = word[w];
    return false;
}