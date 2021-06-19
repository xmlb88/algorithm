#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> res;

bool check(vector<string>& board, int x, int y) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        if (board[i][y] == 'Q') return false;
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') return false;
    }

    // for (int i = x + 1, j = y + 1; i < n && j < n; ++i, ++j) {
    //     if (board[i][j] == 'Q') return false;
    // }

    // for (int i = x + 1, j = y - 1; i < n && j >= 0; ++i, --j) {
    //     if (board[i][j] == 'Q') return false;
    // }

    for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void backtrace(int n, vector<string>& board, int line) {
    if (line == n) {
        res.push_back(board);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check(board, line, i)) {
            board[line][i] = 'Q';
            backtrace(n, board, line + 1);
            board[line][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrace(n, board, 0);
    return res;
}