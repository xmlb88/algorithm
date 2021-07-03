#include <iostream>
#include <vector>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int i = 0;
    for (; i < costs.size(); ++i) {
        coins -= costs[i];
        if (coins < 0) return i;
    }
    return costs.size();
}

// ¼ÆÊýÅÅÐò

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001);
        for (int& cost : costs) {
            freq[cost]++;
        }
        int count = 0;
        for (int i = 1; i <= 100000; i++) {
            if (coins >= i) {
                int curCount = min(freq[i], coins / i);
                count += curCount;
                coins -= i * curCount;
            } else {
                break;
            }
        }
        return count;
    }
};

int maxIceCream(vector<int>& costs, int coins) {
    vector<int> freq(100001, 0);
    for (int& cost : costs) {
        ++freq[cost];
    }

    int count = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (coins >= i) {
            int curCount = min(freq[i], coins / i);
            count += curCount;
            coins -= i * curCount;
        } else break;
    }
    return count;
}