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