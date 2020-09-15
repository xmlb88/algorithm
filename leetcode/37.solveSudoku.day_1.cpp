#include<iostream>
#include<vector>
using namespace std;

// out time
// void solveSudoku(vector<vector<char>>& board) {
//     backtrace(board, 0, 0);
// }

// bool backtrace(vector<vector<char>>& board, int row, int col) {
//     if (col == board[0].size()) {
//         return backtrace(board, row + 1, 0);
//     }
    
//     if (row == board.size()) return true;

//     if (board[row][col] != '.') {
//         return backtrace(board, row, col + 1);
//     }

//     for (char i = '0'; i <= '9'; i++) {
//         if (!isvalid(board, row, col, i)) continue;
//         board[row][col] = i;
//         backtrace(board, row, col + 1);
//         board[row][col] = '.';
//     }

//     return false;

// }

// bool isvalid(vector<vector<char>>& board, int row, int col, char des) {
//     // ÐÐ
//     for (int i = 0; i < board[0].size(); i++) {
//         if (i == col) continue;
//         if (board[row][i] == des) return false;
//     }

//     // ÁÐ
//     for (int i = 0; i < board.size(); i++) {
//         if (i == row) continue;
//         if (board[i][col] == des) return false;
//     }

//     // ¹¬¸ñ
//     for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
//         for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
//             if (i == row && j == col) continue;
//             if (board[i][j] == des) return false;
//         }
//     }

//     return true;
// }

void solveSudoku(vector<vector<char>>& board) {
    backtrace(board, 0, 0);
}

bool backtrace(vector<vector<char>>& board, int row, int col) {
    if (col == board[0].size()) {
        return backtrace(board, row + 1, 0);
    }

    if (row == board.size()) {
        return true;
    }

    if (board[row][col] != '.') {
        return backtrace(board, row, col + 1);
    }

    for (char i = '1'; i <= '9'; i++) {
        if (!isvalid(board, row, col, i)) continue;
        board[row][col] = i;
        if (backtrace(board, row, col + 1)) return true;
        board[row][col] = '.';
    }

    return false;
}

bool isvalid(vector<vector<char>>& board, int row, int col, char des) {
    for (int i = 0; i < board[0].size(); i++) {
        if (board[row][i] == des) return false;
    }

    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] == des) return false;
    }

    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
        for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
            if (board[i][j] == des) return false;
        }
    }

    return true;
}

bool isvalid(vector<vector<char>>& board, int row, int col, char des) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == des) return false;
        if (board[i][col] == des) return false;
        if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == des) return false;
    }

    return true;
}

