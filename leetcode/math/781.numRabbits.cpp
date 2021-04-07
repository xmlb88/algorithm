#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 1 3
int numRabbits(vector<int>& answers) {
    unordered_map<int, int> m;
    for (int ans : answers) {
        m[ans]++;
    }

    int res = 0;
    for (auto& [num, person] : m) {
        while (person > 0) {
            res += num + 1;
            person -= num + 1;
        }
    }
    return res;
}

// https://leetcode-cn.com/problems/rabbits-in-forest/solution/sen-lin-zhong-de-tu-zi-by-leetcode-solut-kvla/
// 

int numRabbit(vector<int>& answers) {
    unordered_map<int, int> count;
    for (int y : answers) {
        ++count[y];
    }

    int ans = 0;
    for (auto& [y, x] : count) {
        ans += 
    }
}