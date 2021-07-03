#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numWays(int n, vector<vector<int>>& relation, int k) {
    queue<int> q;
    q.push(0);
    int step = 0, ways = 0;
    while (!q.empty()) {
        int size = q.size();
        ++step;
        while (size--) {
            int id = q.front();
            q.pop();
            for (auto& relate : relation) {
                if (relate[0] == id) {
                    if (step == k) {
                        if (relate[1] == n - 1) {
                            ++ways;
                        }
                        continue;
                    }
                    q.push(relate[1]);
                }
            }
        }
    }
    return ways;
}

int main() {
    vector<vector<int>> relation = {
        {0, 2}, {2, 1}, {3, 4}, {2, 3}, {1, 4}, {2, 0}, {0, 4}
    };

    cout << numWays(5, relation, 3) << endl;
}