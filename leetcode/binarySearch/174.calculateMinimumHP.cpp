#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS
vector<vector<int>> blood;
vector<int> every_blood;

void backtrack(vector<vector<int>>& dungeon, int i, int j, int hp) {
    if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
        blood.push_back(every_blood);
        return;
    }

    if (i + 1 < dungeon.size()) {
        every_blood.push_back(hp + dungeon[i + 1][j]);
        backtrack(dungeon, i + 1, j, hp + dungeon[i + 1][j]);
        every_blood.pop_back();
    }

    if (j + 1< dungeon[0].size()) {
        every_blood.push_back(hp + dungeon[i][j + 1]);
        backtrack(dungeon, i, j + 1, hp + dungeon[i][j + 1]);
        every_blood.pop_back();
    }
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    every_blood.push_back(dungeon[0][0]);
    backtrack(dungeon, 0, 0, dungeon[0][0]);

    int min_hp = INT_MIN;
    for (auto v : blood) {
        min_hp = max(min_hp, *min_element(v.begin(), v.end()));
    }

    return min_hp >= 0 ? 1 : -min_hp + 1;
}

int main() {
    // vector<vector<int>> dungeon{
    //     {-2, -3, 3},
    //     {-5, -10, 1},
    //     {10, 30, -5}
    // };

    vector<vector<int>> dungeon{{0, 0}};

    cout << calculateMinimumHP(dungeon) << endl;
}


// DFS 优化
int dfs(vector<vector<int>>& dungeon, int m, int n, int i, int j) {
    // 到达终点
    if (i == m - 1 && j == n - 1) {
        return max(1 - dungeon[i][j], 1);
    }

    if (i = m - 1) {
        return max(dfs(dungeon, m, n, i + 1, j) - dungeon[i][j], 1);
    }

    if (j == n - 1) {
        return max(dfs(dungeon, m, n, i, j + 1) - dungeon[i][j], 1);
    }

    return max(min(dfs(dungeon, m, n, i + 1, j), dfs(dungeon, m, n, i, j + 1)) - dungeon[i][j], 1);
}

// TODO:

vector<vector<int>> hp;
int dfs(vector<vector<int>>& dungeon, int m, int n, int i, int j) {
    if (hp[i][j] > 0) return hp[i][j];

    if (i == m - 1 && j = n - 1) {
        hp[i][j] = 
    }
}

// DFS

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

N N N
N N N
N N 6

N N N 
N N 5
N 1 6

N N 2
N 11 1
1 1 6

N 5 2
6 11 1
1 1 6

7 5 2
6 11 1
1 1 6
int dfs(vector<vector<int>>& dungeon, int i, int j) {
    int m = dungeon.size(), n = dungeon[0].size();

    // 到达终点
    if (i == m - 1 && j == n - 1) {
        return max(1 - dungeon[i][j], 1);
    }

    if (i == m - 1) {
        return max(dfs(dungeon, i, j + 1) - dungeon[i][j], 1);
    }

    if (j == n - 1) {
        return max(dfs(dungeon, i + 1, j) - dungeon[i][j], 1);
    }

    return max(min(dfs(dungeon, i + 1, j), dfs(dungeon, i, j + 1)) - dungeon[i][j], 1);
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    return dfs(dungeon, 0, 0);
}

// 备忘录
vector<vector<int>> hp;
int dfs(vector<vector<int>>& dungeon, int i, int j) {
    if (hp[i][j] > 0) return hp[i][j];
    int m = dungeon.size(), n = dungeon[0].size();
    if (i == m - 1 && j == n - 1) {
        hp[i][j] = max(1 - dungeon[i][j], 1);
    } else if (i == m - 1) {
        hp[i][j] = max(dfs(dungeon, i, j + 1) - dungeon[i][j], 1);
    } else if (j == n - 1) {
        hp[i][j] = max(dfs(dungeon, i + 1, j) - dungeon[i][j], 1);
    } else {
        hp[i][j] = max(min(dfs(dungeon, i + 1, j), dfs(dungeon, i, j + 1)) - dungeon[i][j], 1);
    }
    return hp[i][j];
}


int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    hp.resize(m, vector<int> (n, 0));
    return dfs(dungeon, 0, 0);
}

// dp数组
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    // 初始化
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, INT_MAX));
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == m - 1 && j == n - 1) {
                dp[i][j] = max(1 - dungeon[i][j], 1);
            } else if (i == m - 1) {
                dp[i][j] = max(dp[i][j + 1] - dungeon[i][j], 1);
            } else if (j == n - 1) {
                dp[i][j] = max(dp[i + 1][j] - dungeon[i][j], 1);
            } else {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
    }
    return dp[0][0];
}