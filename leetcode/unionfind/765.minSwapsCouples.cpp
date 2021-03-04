#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 贪心
// int minSwapsCouples(vector<int>& row) {
//     int n = row.size();
//     int minSwap = 0;
//     for (int i = 0; i < n; i += 2) {
//         int lperson = row[i], rperson = lperson + 1;
//         if (lperson & 1) rperson = lperson - 1;
//         if (row[i + 1] == rperson) continue;
//         swap(row[i + 1], *find(row.begin(), row.end(), rperson));
//         ++minSwap;
//     }
//     return minSwap;
// }

// 贪心优化
int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int minSwap = 0;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[row[i]] = i;
    }

    for (int i = 0; i < n - 1; i += 2) {
        int lperson = row[i], rperson = lperson ^ 1;
        if (row[i + 1] == rperson) continue;
        int other = row[i + 1];
        // int changePos = pos[rperson];
        swap(row[i + 1], row[pos[rperson]]);
        swap(pos[rperson], pos[other]);
        // row[changePos] = other;
        // pos[other] = changePos;
        ++minSwap;
    }

    return minSwap;
}

int main() {
    vector<int> row = {0,2,4,6,7,1,3,5};
    cout << minSwapsCouples(row) << endl;
}