#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded) {
    int n = encoded.size();
    vector<int> res(n + 1);
    res[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] = res[i + 1] ^ encoded[i];
    }
    return res;
}

// int main() {
//     vector<int> encoded{6, 5, 4, 6};
//     for (auto& num : decode(encoded)) {
//         cout << num << " ";
//     }
// }

// 
bool check(vector<int>& encoded, int last) {
    for (int i = encoded.size() - 1; i >= 0; --i) {
        last = last ^ encoded[i];
        if (last == 0) return false;
    }
    return true;
}

vector<int> decode(vector<int>& encoded) {
    int n = encoded.size();
    int last = 1;
    while (true) {
        if (check(encoded, last)) {
            vector<int> res(n + 1);
            res[n] = last;
            for (int i = n - 1; i >= 0; --i) {
                res[i] = res[i + 1] ^ encoded[i];
            }
            return res;
        }
        ++last;
    }
    return {};
}

// [1, 2, 3]
// [3, 1]
// 1^2 2^3 3^4
vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total ^= i;
    }
    int odd = 0;
    for (int i = 1; i < n - 1; i += 2) {
        odd ^= encoded[i];
    }

    vector<int> perm(n);
    perm[0] = total ^ odd;
    for (int i = 0; i < n - 1; ++i) {
        perm[i + 1] = perm[i] ^ encoded[i];
    }
    return perm;
}


// 先求首位元素
vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    // 1 - n-1异或结果
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total ^= i;
    }

    // 除res[0]以外的异或结果
    int odd = 0;
    for (int i = 1; i < n - 1; i += 2) {
        odd ^= encoded[i];
    }

    vector<int> res(n);
    res[0] = total ^ odd;
    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1] ^ encoded[i - 1];
    }
    return res;
}

// 先求最后一位元素
vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total ^= i;
    }

    int odd = 0;
    for (int i = 0; i < n - 1; i += 2) {
        odd ^= encoded[i];
    }

    vector<int> res(n);
    res[n - 1] = total ^ odd;
    for (int i = n - 2; i >= 0; --i) {
        res[i] = res[i + 1] ^ encoded[i];
    }
    return res;
}