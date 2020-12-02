#include <iostream>
#include <vector>
using namespace std;

string tictactoe(vector<string>& board) {
    int n = board.size();
    int x = 0, o = 0, blank = 0;
    string win = "";
    // ÅÐ¶ÏÐÐ
    for (int i = 0; i < n; i++) {
        char flag = board[i][0];
        if (flag == ' ') continue;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == flag) count++;
        }
        if (count == n) {
            win.push_back(flag);
            break;
        }
    }

    if (!win.empty()) return win;

    // ÅÐ¶ÏÁÐ
    for (int j = 0; j < n; j++) {
        char flag = board[0][j];
        if (flag == ' ') continue;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == flag) count++;
        }
        if (count == n) {
            win.push_back(flag);
            break;
        }
    }

    if (!win.empty()) return win;

    // ÅÐ¶Ï¶Ô½ÇÏß
    char flag_l = board[0][0];
    if (flag_l != ' ') {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][i] == flag_l) count++;
        }
        if (count == n) win.push_back(flag_l);
    }

    if (!win.empty()) return win;

    char flag_r = board[0][n - 1];
    if (flag_r != ' ') {
        int count = 0;
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == flag_r) count++;
        }
        if (count == n) win.push_back(flag_r);
    }

    if (!win.empty()) return win;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') o++;
            else if (board[i][j] == 'X') x++;
            else if (board[i][j] == ' ') blank++;
        }
    }

    if (blank == 0) return "Draw";
    else return "Pending";
}