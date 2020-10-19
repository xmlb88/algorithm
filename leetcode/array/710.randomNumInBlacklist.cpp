#include <iostream>
#include <vector>
using namespace std;

// 维护白名单 [超出时间限制，超出空间限制]
class Solution {
public:
    vector<int> whiteList;
    Solution(int N, vector<int>& blacklist) {
        for (int i = 0; i < N; i++) {
            whiteList.push_back(i);
        }

        for (int num : blacklist) {
            whiteList[num] = -1;
        }

        for (auto it = whiteList.begin(); it != whiteList.end(); it++) {
            if (*it == -1) {
                whiteList.erase(it);
            }
            else it++;
        }
    }
    
    int pick() {
        return whiteList[rand() % whiteList.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {

    }
    
    int pick() {

    }
};