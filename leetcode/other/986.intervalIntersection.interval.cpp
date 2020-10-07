#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int i = 0, j = 0;
    vector<vector<int>> result;
    while (i < A.size() && j < B.size()) {
        int a1 = A[i][0], b1 = A[i][1];
        int a2 = B[j][0], b2 = B[j][1];

        if (a1 <= b2 && a2 <= b1) {
            result.push_back({max(a1, a2), min(b1, b2)});
        }

        if (b1 < b2) i++;
        else j++;
    }
    return result;
}