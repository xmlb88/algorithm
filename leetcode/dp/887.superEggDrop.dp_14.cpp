#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> memo;
int superEggDrop(int K, int N) {
    // base case
    if (K == 1) return N;
    if (N == 0) return 0;

    string key = to_string(K) + "," + to_string(N);
    if (memo.count(key)) return memo[key];

    int res = INT_MAX;
    for (int i = 1; i <= N; i++) {
        res = min(res, max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)) + 1);
    }

    memo[key] = res;
    return res;
}


// ¶þ·Ö