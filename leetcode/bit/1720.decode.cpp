#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> res{first};
    for (int num : encoded) {
        res.push_back(res.back() ^ num);
    }
    return res;
}

// [1, 2, 3]
// [1]
// 1 ^ ? = 1 ? = 0
// 0 ^ ? = 2 ? = 0 ^ 2 = 2
// 2 ^ ? = 3 ? = 2 ^ 3 = 1

vector<int> decode(vector<int>& encode, int first) {
    int n = encode.size() + 1;
    vector<int> arr(n);
    arr[0] = first;
    for (int i = 1; i < n; i++) {
        arr[i] = encode[i - 1] ^ arr[i - 1];
    }
    return arr;
}