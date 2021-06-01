#include <iostream>
#include <vector>
using namespace std;

// 7,4,5,3,8
// queries : <favoriteType, favoriteDay, dailyCap>
vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int n = candiesCount.size(), m = queries.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + candiesCount[i - 1];
    }

    vector<bool> res(m, true);
    for (int i = 0; i < m; ++i) {
        int favoriteType = queries[i][0];
        int favoriteDay = queries[i][1];
        int dailyCap = queries[i][2];

        if ((favoriteDay + 1) * static_cast<long long>(dailyCap) <= pre[favoriteType]) res[i] = false;
        if (favoriteDay + 1 > pre[favoriteType + 1]) res[i] = false;
    }
    return res;
}

// pre = [0, 7, 11, 16, 19, 27]

int main() {
    // vector<int> candiesCount = {7,4,5,3,8};
    // vector<vector<int>> quer = {
    //     {0,2,2}, {4,2,4}, {2,13,1000000000},
    // };
    vector<int> candiesCount = {5,2,6,4,1};
    vector<vector<int>> quer = {
        {3,1,2}, {4,10,3}, {3,10,100}, {4,100,30}, {1,3,1},
    };
    for (auto b : canEat(candiesCount, quer)) {
        cout << b << " ";
    }
    cout << endl;
}