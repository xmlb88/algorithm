#include <iostream>
#include <vector>
using namespace std;

// wrong code
// int movingCount(int m, int n, int k) {
//     int count = 0;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (sum(i) + sum(j) <= k) count++;
//         }
//     }
//     return count;
// }

// int sum(int num) {
//     return num / 100 + num / 10 % 10 + num % 10;
// }

// DFS
vector<vector<int>> board;
int count = 0;
int movingCount(int m, int n, int k) {
    board.resize(m, vector<int>(n, 0));
    move(0, 0, m, n, k);
    return count;
}

void move(int i, int j, int m, int n, int k) {
    // 到达sum > k的地方，返回
    if (singleSum(i) + singleSum(j) > k) return;
    // 到达重复的地方，返回
    if (board[i][j] == 1) return;
    // board[i][j] = 1标记走过了，count + 1
    board[i][j] = 1;
    count += 1;

    // 向4个方向走
    if (i + 1 < m) move(i + 1, j, m, n, k);
    if (i - 1 >= 0) move(i - 1, j, m, n, k);
    if (j + 1 < n) move(i, j + 1, m, n, k);
    if (j - 1 >= 0) move(i, j - 1, m, n, k);

}

int singleSum(int num) {
    return num / 100 + num / 10 % 10 + num % 10;
}