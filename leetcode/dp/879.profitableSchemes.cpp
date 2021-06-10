#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int dfs(vector<int>& group, vector<int>& profit, int index, int left_person, int sum, vector<vector<vector<int>>>& memo) {
    if (left_person < 0) return 0;
    if (index == group.size()) return sum <= 0;
    if (sum < 0) sum = 0;
    if (memo[index][left_person][sum] == -1) {
        memo[index][left_person][sum] = dfs(group, profit, index + 1, left_person - group[index], sum - profit[index], memo) % mod +
            dfs(group, profit, index + 1, left_person, sum, memo) % mod;
    }
    return memo[index][left_person][sum];
}

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    vector<vector<vector<int>>> memo(group.size(), vector<vector<int>> (n + 1, vector<int> (minProfit + 1, -1)));
    return dfs(group, profit, 0, n, minProfit, memo) % mod;
}