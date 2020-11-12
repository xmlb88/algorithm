#include <iostream>
#include <string>
#include <vector>
using namespace std;

int res = INT_MAX;
int findRotateSteps(string ring, string key) {
    int step = key.size();
    dfs(ring, 0, key, 0, step);
    return res;
}

void dfs(string ring, int i, string key, int j, int step) {
    // base case
    if (j == key.size()) {
        res = min(res, step);
        return;
    }

    // À≥ ±’Î
    for (int p = 0; p < ring.size(); p++) {
        if (ring[(i + p) % ring.size()] == key[j]) {
            dfs(ring, (i + p) % ring.size(), key, j + 1, step + p);
            break;
        }
    }
    // ƒÊ ±’Î
    for (int p = 0; p < ring.size(); p++) {
        if (i - p >= 0 && ring[i - p] == key[j]) {
            dfs(ring, i - p, key, j + 1, step + p);
            break;
        } else if (i - p < 0 && ring[ring.size() - abs(i - p)] == key[j]) {
            dfs(ring, ring.size() - abs(i - p), key, j + 1, step + p);
            break;
        }
    }
}
// godding  i = 4 

// ±∏Õ¸¬º”≈ªØ

vector<vector<int>> memo;
int findRotateSteps(string ring, string key) {
    memo.assign(ring.size(), vector<int> (key.size(), -1));
    return dfs(ring, 0, key, 0) + key.size();
}

int dfs(string ring, int i, string key, int j) {
    // base case
    if (j == key.size()) {
        return 0;
    }

    if (memo[i][j] != -1) return memo[i][j];

    // ‘⁄”“±ﬂ’“
    int right_step;
    for (int p = 0; p < ring.size(); p++) {
        if (ring[(i + p) % ring.size()] == key[j]) {
            right_step = dfs(ring, (i + p) % ring.size(), key, j + 1) + p;
            break;
        }
    }
    // ‘⁄◊Û±ﬂ’“
    int left_step;
    for (int p = 0; p < ring.size(); p++) {
        if (i - p >= 0 && ring[i - p] == key[j]) {
            left_step = dfs(ring, i - p, key, j + 1) + p;
            break;
        } else if (i - p < 0 && ring[ring.size() - abs(i - p)] == key[j]) {
            left_step = dfs(ring, ring.size() - abs(i - p), key, j + 1) + p;
            break;
        }
    }

    memo[i][j] = min(left_step, right_step);
    return memo[i][j];
}




vector<vector<int>> memo;
int findRotateSteps(string ring, string key) {
    memo.assign(ring.size(), vector<int> (key.size(), -1));
    return dfs(ring, 0, key, 0) + key.size();
}

int dfs(string ring, int i, string key, int j) {
    // base case
    if (j == key.size()) {
        return 0;
    }

    if (memo[i][j] != -1) return memo[i][j];

    // // ‘⁄”“±ﬂ’“
    // int right_step;
    // for (int p = 0; p < ring.size(); p++) {
    //     if (ring[(i + p) % ring.size()] == key[j]) {
    //         right_step = dfs(ring, (i + p) % ring.size(), key, j + 1) + p;
    //         break;
    //     }
    // }
    // // ‘⁄◊Û±ﬂ’“
    // int left_step;
    // for (int p = 0; p < ring.size(); p++) {
    //     if (i - p >= 0 && ring[i - p] == key[j]) {
    //         left_step = dfs(ring, i - p, key, j + 1) + p;
    //         break;
    //     } else if (i - p < 0 && ring[ring.size() - abs(i - p)] == key[j]) {
    //         left_step = dfs(ring, ring.size() - abs(i - p), key, j + 1) + p;
    //         break;
    //     }
    // }

    int n = ring.size();
    int step = INT_MAX;
    for (int p = 0; p < ring.size(); p++) {
        if (ring[p] == key[j]) {
            int dis = 
            step = min(step, dfs(ring, p, key, j + 1) + min(abs(p - i), n - abs(p - i)));
        }
    }

    // memo[i][j] = min(left_step, right_step);
    memo[i][j] = step;
    return memo[i][j];
}


vector<vector<int>> memo;
int findRotateSteps(string ring, string key) {
    memo.assign(ring.size(), vector<int> (26, -1));
    return dfs(ring, 0, key, 0) + key.size();
}

int dfs(string ring, int i, string key, int j) {
    // base case
    if (j == key.size()) {
        return 0;
    }

    if (memo[i][key[j] - 'a'] != -1) return memo[i][key[j] - 'a'];

    // ‘⁄”“±ﬂ’“
    int right_step;
    for (int p = 0; p < ring.size(); p++) {
        if (ring[(i + p) % ring.size()] == key[j]) {
            right_step = dfs(ring, (i + p) % ring.size(), key, j + 1) + p;
            break;
        }
    }
    // ‘⁄◊Û±ﬂ’“
    int left_step;
    for (int p = 0; p < ring.size(); p++) {
        if (i - p >= 0 && ring[i - p] == key[j]) {
            left_step = dfs(ring, i - p, key, j + 1) + p;
            break;
        } else if (i - p < 0 && ring[ring.size() - abs(i - p)] == key[j]) {
            left_step = dfs(ring, ring.size() - abs(i - p), key, j + 1) + p;
            break;
        }
    }

    memo[i][key[j] - 'a'] = min(left_step, right_step);
    return memo[i][key[j] - 'a'];
}

// "a b a b c a b"
// "a c b a a c b a"

// [7][8]

// [0][0] = [0][1] + 0;
// [0][1] = [4][2] + 3;
// [4][2] = [3][3] + 1;
// [3][3] = 

// [0][0] = [0][1] + 0;
// [0][1] = [4][2] + 3;
// [4][2] = [3][3] + 1;
// [3][3] = [2][4] + 1;
// [2][4] = [2][5] + 0;
// [2][5] = [4][6] + 2; [2][5] = 4; [2][c] = 4;
// [4][6] = [3][7] + 1; [4][6] = 2; [4][b] = 2;
// [3][7] = [2][8] + 1; [3][7] = 1; [3][a] = 1;


// dp
int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<int> pos[26];
    for (int i = 0; i < n; i++) {
        pos[ring[i] - 'a'].push_back(i);
    }

    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(auto i : pos[key[0] - 'a']) {
        dp[0][i] = min(i, n - i) + 1;
    }

    for (int i = 1; i < m; i++) {
        for (auto j : pos[key[i] - 'a']) {
            for (auto k : pos[key[i - 1] - 'a']) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k) + 1));
            }
        }
    }

    return *min_element(dp[m - 1], dp[m - 1] + n) + key.size();
}

// dfs
int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[ring[i] - 'a'].push_back(i);
    }

    vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
    for (auto i : pos[key[0] - 'a']) {
        dp[0][i] = min(i, n - i);
    }

    for (int i = 1; i < m; i++) {
        for (auto j : pos[key[i] - 'a']) {
            for (auto k : pos[key[i - 1] - 'a']) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)));
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[m - 1][i]);
    }

    return res + m;
}



class Solution {
public:

vector<vector<int>> memo;
int findRotateSteps(string ring, string key) {
    memo.assign(ring.size(), vector<int> (key.size(), -1));
    return dfs(ring, 0, key, 0) + key.size();
}

int dfs(string ring, int i, string key, int j) {
    int n = ring.size(), m = key.size();

    if (j == key.size()) {
        return 0;
    }

    if (memo[i][j] != -1) return memo[i][j];

    int step = INT_MAX;
    for (int p = 0; p < ring.size(); p++) {
        if (ring[p] == key[j]) {
            step = min(step, dfs(ring, p, key, j + 1) + min(abs(p - i), n - abs(p - i)));
        }
    }

    memo[i][j] = step;
    return memo[i][j];
}
};
