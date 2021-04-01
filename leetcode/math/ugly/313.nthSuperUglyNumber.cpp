#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int m = primes.size();
    vector<int> pos(m, 0);
    vector<int> ugly(n);
    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
        int min_ugly = INT_MAX;
        vector<int> min_index;
        for (int j = 0; j < m; ++j) {
            int u = ugly[pos[j]] * primes[j];
            if (u < min_ugly) {
                min_ugly = u;
                min_index.clear();
                min_index.push_back(j);
            } else if (u == min_ugly) {
                min_index.push_back(j);
            }
        }
        ugly[i] = min_ugly;
        for (auto& index : min_index) {
            pos[index]++;
        }
    }
    return ugly[n - 1];
}

int main() {
    vector<int> primes{2,7,13,19};
    cout << nthSuperUglyNumber(12, primes) << endl;
}

// ¶Ñ
int nthSuperUglyNumber(int n, vector<int>& primes) {
    priority_queue<long long, vector<long long>, greater<long long>> q;
    q.push(1);
    unordered_set<long long> s;
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res = q.top();
        q.pop();
        for (auto& x : primes) {
            if (s.find(res * x) == s.end()) {
                q.push(res * x);
                s.insert(res * x);
            }
        }
    }
    return res;
}