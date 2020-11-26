#include <iostream>
#include <string>
using namespace std;

vector<vector<string>> res;
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    dfs(board, 0, n);
    return res;
}

void dfs(vector<string>& board, int level, int n) {
    if (level == n) {
        res.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isvalid(board, level, i)) {
            board[level][i] = 'Q';
            dfs(board, level + 1, n);
            board[level][i] = '.';
        }
    }
}

bool isvalid(vector<string>& board, int row, int col) {
    int n = board.size();

    // Êú
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // ×óÉÏ½Ç
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}