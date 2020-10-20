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
    int sz;
    unordered_map<int, int> mapping;
    Solution(int N, vector<int>& blacklist) {
        sz = N - blacklist.size();
        for (int b : blacklist) {
            mapping[b] = 666;
        }
        int last = N - 1;
        
        for (int b : blacklist) {
            if (b >= sz) {
                continue;
            }
            while (mapping.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }


    }
    
    int pick() {
        int index = rand() % sz;

        if (mapping.count(index)) {
            return mapping[index];
        }

        return index;
    }
};


class Solution {
public:
    int sz;
    unordered_map<int, int> mapping;
    Solution(int N, vector<int>& blacklist) {
        sz = N - blacklist.size();
        for (int n : blacklist) {
            mapping[n] = 666;
        }
        
        int last = N - 1;
        for (int n : blacklist) {
            if (n >= sz) {
                continue;
            }

            while (mapping.count(last)) {
                last--;
            }

            mapping[n] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand() % sz;
        if (mapping.count(index)) {
            return mapping[index];
        }
        return index;
    }
};