#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// DFS
// vector<int> visited;
// vector<vector<int>> friendCircle;
// int findCircleNum(vector<vector<int>>& M) {
//     int n = M.size();
//     if (n == 0) return 0;
//     visited.assign(n, false);
//     vector<int> circle;

//     for (int i = 0; i < n; i++) {
//         dfs(M, i, circle);
//     }

//     return friendCircle.size();
// }

// void dfs(vector<vector<int>>& M, int index, vector<int> circle) {
//     if (visited[index]) return;

//     circle.push_back(index);
//     visited[index] = true;
//     vector<int> newFriend;
//     for (int i = 0; i < n; i++) {
//         if (visited[i]) continue;

//         if (M[index][i] == 1) {
//             newFriend.push_back(i);
//         }
//     }

//     if (newFriend.empty()) {
//         friendCircle.push_back(circle);
//         return;
//     } else {
//         for (int num : newFriend) {
//             dfs(M, num, circle);
//         }
//     }
// }

// vector<vector<int>> friendCircle;
// vector<bool> visited;
// int findCircleNum(vector<vector<int>>& M) {
//     int n = M.size();
//     if (n == 0) return 0;

//     visited.assign(n, false);
//     vector<int> circle;
//     for (int i = 0; i < n; i++) {
//         if (visited[i]) continue;
//         circle.clear();
//         dfs(M, i, circle);
//     }

//     return friendCircle.size();
// }

// void dfs(vector<vector<int>>& M, int index, vector<int>& circle) {
//     int n = M.size();
//     // if (find(circle.begin(), circle.end(), index) != circle.end()) return;
//     visited[index] = true;

//     circle.push_back(index);
//     vector<int> newFriend;
//     for (int i = 0; i < n; i++) {
//         if (find(circle.begin(), circle.end(), i) != circle.end()) continue;

//         if (M[index][i] == 1) {
//             newFriend.push_back(i);
//         }
//     }

//     if (newFriend.empty()) {
//         friendCircle.push_back(circle);
//         return;
//     } else {
//         for (int num : newFriend) {
//             dfs(M, num, circle);
//         }
//     }
// }

vector<bool> visited;
int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    visited.assign(M.size(), false);

    int count = 0;
    for (int i = 0; i < M.size(); i++) {
        if (!visited[i]) {
            dfs(M, i);
            count++;
        }
    }
    return count;
}

void dfs(vector<vector<int>>& M, int i) {
    if (visited[i]) return;
    visited[i] = true;
    for (int j = 0; j < M.size(); j++) {
        if (visited[j]) continue;
        if (M[i][j] == 1) {
            dfs(M, j);
        }
    }
}



// BFS
int findCircleNum(vector<vector<int>>& M) {

}