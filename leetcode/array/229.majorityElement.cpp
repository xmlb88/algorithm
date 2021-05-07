#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// ±©Á¦hash
vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
    }
    vector<int> res;
    for (auto& [n, count] : m) {
        if (count > nums.size() / 3) res.push_back(n);
    }
    return res;
}

// MooreÍ¶Æ±·¨
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int candi_1, count_1 = 0;
    int candi_2, count_2 = 0;

    for (int num : nums) {
        if (num == candi_1) {
            ++count_1;
            continue;
        }

        if (num == candi_2) {
            ++count_2;
            continue;
        }

        if (count_1 == 0) {
            candi_1 = num;
            count_1 = 1;
            continue;
        }

        if (count_2 == 0) {
            candi_2 = num;
            count_2 = 1;
            continue;
        }

        --count_1; --count_2;
    }

    count_1 = 0, count_2 = 0;
    for (int num : nums) {
        if (num == candi_1) ++count_1;
        else if (num == candi_2) ++count_2;
    }

    vector<int> res;
    if (count_1 > n / 3) res.push_back(candi_1);
    if (count_2 > n / 3) res.push_back(candi_2);
    return res;
}