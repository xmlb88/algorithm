#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// DFS
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int n = board.size(), m = board[0].size();
    int x = click[0], y = click[1];
    if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return board;
    }

    dfs(board, x, y);
    return board;
}

constexpr static int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr static int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<vector<char>>& board, int x, int y) {
    int n = board.size(), m = board[0].size();
    // base case
    if (x < 0 || x >= n) return;
    else if (y < 0 || y >= m) return;
    else if (board[x][y] != 'E') return;


    // 设置数字
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (x + dx[i] >=0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && board[x + dx[i]][y + dy[i]] == 'M') {
            count++;
        }
    }

    if (count > 0) {
        board[x][y] = count + '0';
    } else {
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
            dfs(board, x + dx[i], y + dy[i]);
        }
    }
}

// [0, 0] [0, 1] [0, 2]
// [1, 0] [1, 1] [1, 2]
// [2, 0] [2, 1] [2, 2]

// BFS

constexpr static int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr static int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int n = board.size(), m = board[0].size();
    int x = click[0], y = click[1];
    if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return board;
    }

    queue<vector<int>> q;
    q.push(click);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            vector<int> pos = q.front();
            q.pop();

            // 检查边界及是否点击过
            if (pos[0] < 0 || pos[0] >= n) continue;
            if (pos[1] < 0 || pos[1] >= m) continue;
            if (board[pos[0]][pos[1]] != 'E') continue;

            // 计算周围炸弹
            int count = 0;
            for (int i = 0; i < 8; i++) {
                if (pos[0] + dx[i] >= 0 && pos[0] + dx[i] < n && pos[1] + dy[i] >= 0 && pos[1] + dy[i] < m && board[pos[0] + dx[i]][pos[1] + dy[i]] == 'M') {
                    count++;
                }
            }

            if (count > 0) {
                board[pos[0]][pos[1]] = count + '0';
            } else {
                board[pos[0]][pos[1]] = 'B';
                for (int i = 0; i < 8; i++) {
                    q.push({pos[0] + dx[i], pos[1] + dy[i]});
                }
            }
        }
    }
    return board;
}