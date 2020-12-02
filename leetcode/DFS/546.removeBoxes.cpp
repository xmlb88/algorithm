#include <iostream>
#include <vector>
using namespace std;

int res = INT_MIN;
int removeBoxes(vector<int>& boxes) {
    int integral = 0;
    dfs(boxes, integral);
    return res;
}

void dfs(vector<int> boxes, int integral) {
    int n = boxes.size();
    if (n == 0) {
        res = max(res, integral);
        return;
    }
    for (int i = 0; i < n; i++) {
        int count = 0, temp = boxes[i], j = i;
        while (j < n && boxes[j] == temp) {
            count++;
            j++;
        }
        vector<int> vec = boxes;
        vec.erase(vec.begin() + i, vec.begin() + i + count);
        dfs(vec, integral + count * count);
    }
}

