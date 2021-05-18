#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> prexor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prexor[i] = prexor[i - 1] ^ arr[i - 1];
    }

    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                if ((prexor[j] ^ prexor[i]) == (prexor[k + 1] ^ prexor[j])) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> prexor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prexor[i] = prexor[i - 1] ^ arr[i - 1];
    }

    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int k = i + 1; k < n; ++k) { 
            if (prexor[i] == prexor[k + 1]) {
                count += k - i;
            }
        }
    }
    return count;
}

// hash
int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }

    unordered_map<int, int> cnt, total;
    int res = 0;
    for (int k = 0; k < n; ++k) {
        if (cnt.count(s[k + 1])) {
            res += cnt[s[k + 1]] * k - total[s[k + 1]];
        }
        ++cnt[s[k]];
        total[s[k]] += k;
    }

    return res;
}


int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> prexor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prexor[i] = prexor[i - 1] ^ arr[i - 1];
    }

    unordered_map<int, int> cnt, total;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt.count(prexor[i + 1])) {
            res += cnt[prexor[i + 1]] * i - total[prexor[i + 1]];
        }
        ++cnt[prexor[i]];
        total[prexor[i]] += i;
    }
    return res;
}

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> cnt, total;
    int res = 0, prexor = 0;

    for (int k = 0; k < n; ++k) {
        int val = arr[k];
        if (cnt.count(prexor ^ val)) {
            res += cnt[prexor ^ val] * k - total[prexor ^ val];
        }

        ++cnt[prexor];
        total[prexor] += k;
        prexor ^= val;
    }
    return res;
}

// 
int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> prexor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prexor[i] = prexor[i - 1] ^ arr[i - 1];
    }

    unordered_map<int, int> cnt, total;
    int res = 0;
    for (int k = 0; k < n; ++k) {
        if (cnt.find(prexor[k + 1]) != cnt.end()) {
            res += cnt[prexor[k + 1]] * k - total[prexor[k + 1]];
        }
        ++cnt[prexor[k]];
        total[prexor[k]] += k;
    }
    return res;
}

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> cnt, total;
    int prexor = 0, res = 0;
    for (int k = 0; k < n; ++k) {
        if (cnt.find(prexor ^ arr[k]) != cnt.end()) {
            res += cnt[prexor ^ arr[k]] * k - total[prexor ^ arr[k]];
        }

        ++cnt[prexor];
        total[prexor] += k;
        prexor ^= arr[k];
    }
    return res;
}