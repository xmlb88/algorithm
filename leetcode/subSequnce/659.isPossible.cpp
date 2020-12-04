#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// ¹þÏ£±í + ×îÐ¡¶Ñ
bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int& x : nums) {
        if (mp.find(x) == mp.end()) {
            mp[x] = priority_queue<int, vector<int>, greater<int>>();
        }

        
    }
}