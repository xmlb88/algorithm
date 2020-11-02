#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++) {
        if (find(result.begin(), result.end(), nums1[i]) != result.end()) continue;
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                break;
            }
        }
    }
    return result;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set;
    for (int num : nums1) {
        set.insert(num);
    }

    vector<int> result;
    for (int num : nums2) {
        if (set.count(num) && find(result.begin(), result.end(), num) == result.end())
            result.push_back(num);
    }

    return result;
}