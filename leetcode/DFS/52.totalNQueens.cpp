#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt = 0;

bool check(vector<string>& board, int x, int y) {
    int n = board.size();

    for (int i = 0; i < x; ++i) {
        if (board[i][y] == 'Q') return false;
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') return false;
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void backtrace(vector<string>& board, int row) {
    int n = board.size();
    if (row == n) {
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check(board, row, i)) {
            board[row][i] = 'Q';
            backtrace(board, row + 1);
            board[row][i] = '.';
        }
    }
}

int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrace(board, 0);
    return cnt;
}