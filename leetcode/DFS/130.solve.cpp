#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS
void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++) {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        dfs(board, 0, j);
        dfs(board, n - 1, j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'o') {
                board[i][j] = 'O';
            }
        }
    }

    return;
}

void dfs(vector<vector<char>>& board, int x, int y) {
    int n = board.size(), m = board[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') return;

    board[x][y] = 'o';
    dfs(board, x - 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
    dfs(board, x + 1, y);
}


// BFS
constexpr static int dx[4] = {-1, 0, 0, 1};
constexpr static int dy[4] = {0, -1, 1, 0};
void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int n = board.size(), m = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') {
            q.push(make_pair(i, 0));
            board[i][0] = 'o';
        }
        if (board[i][m - 1] == 'O') {
            q.push(make_pair(i, m - 1));
            board[i][m - 1] = 'o';
        }
    }

    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') {
            q.push(make_pair(0, j));
            board[0][j] = 'o';
        }
        if (board[n - 1][j] == 'O') {
            q.push(make_pair(n - 1, j));
            board[n - 1][j] = 'o';
        }
    }

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto kv = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = kv.first + dx[i], y = kv.second + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
                    q.push(make_pair(x, y));
                    board[x][y] = 'o';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'o') {
                board[i][j] = 'O';
            }
        }
    }

    return;
}