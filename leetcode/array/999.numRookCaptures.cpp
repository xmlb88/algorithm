#include <iostream>
#include <vector>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    int num = 0;
    int n = board.size(), m = board.at(0).size();
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1 && y != -1) break;
    }

    for (int x_up = x - 1; x_up >= 0; --x_up) {
        if (board[x_up][y] == 'p') {
            ++num;
            break;
        } else if (board[x_up][y] == 'B') break;
    }

    for (int x_down = x + 1; x_down < n; ++x_down) {
        if (board[x_down][y] == 'p') {
            ++num;
            break;
        } else if (board[x_down][y] == 'B') break;
    }

    for (int y_left = y - 1; y_left >= 0; --y_left) {
        if (board[x][y_left] == 'p') {
            ++num;
            break;
        } else if (board[x][y_left] == 'B') break;
    }

    for (int y_right = y + 1; y_right < m; ++y_right) {
        if (board[x][y_right] == 'p') {
            ++num;
            break;
        } else if (board[x][y_right] == 'B') break;
    }

    return num;
}