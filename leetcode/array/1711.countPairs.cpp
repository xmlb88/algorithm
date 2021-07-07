#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
int countPairs(vector<int>& deleciousness) {
    int count = 0;
    int max_val = 0;
    for (auto food : deleciousness) {
        max_val = max(max_val, food);
    }

    max_val *= 2;
    unordered_map<int, int> m;
    for (auto food : deleciousness) {
        for (int i = 1; i <= max_val; i <<= 1) {
            if (m.find(i - food) != m.end()) {
                count = (count + m[i - food]) % mod;
            }
        }
        ++m[food];
    }
    return count;
}

int main() {
    vector<int> delecious = {1,3,5,7,9};
    cout << countPairs(delecious) << endl;
}