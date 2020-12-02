#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    int n = nums1.size(), m = nums2.size();
    for (int i = max(0, k - m); i <= min(k, n); i++) {
        vector<int> vec = merge(selectNumber(nums1, i), selectNumber(nums2, k - i));
        // res = lexicographical_compare(res.begin(), res.end(), vec.begin(), vec.end()) ? vec : res;
        if (res < vec) res = vec;
    }
    return res;
}

vector<int> selectNumber(vector<int>& num, int k) {
    int n = num.size() - k;
    if (n == 0) return num;
    vector<int> res;
    for (int i = 0; i < num.size(); i++) {
        while (!res.empty() && res.back() < num[i] && n > 0) {
            res.pop_back();
            n--;
        }
        res.push_back(num[i]);
    }
    
    while (n--) {
        res.pop_back();
    }

    return res;
}

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    if (nums1.empty()) return nums2;
    if (nums2.empty()) return nums1;
    int i = 0, j = 0;
    vector<int> res;
    // while (i < nums1.size() || j < nums2.size()) {
    //     if (i == nums1.size() || nums1[i] < nums2[j]) {
    //         res.push_back(nums2[j]);
    //         j++;
    //     } else if (j == nums2.size() || nums1[i] > nums2[j]) {
    //         res.push_back(nums1[i]);
    //         i++;
    //     } else if (nums1[i] == nums2[j] && (nums1[i + 1] > nums2[j + 1])) {
    //         res.push_back(nums1[i]);
    //         i++;
    //     } else {
    //         res.push_back(nums2[j]);
    //         j++;
    //     }
    // }

    auto iter1 = nums1.begin(), iter2 = nums2.begin();
        while (iter1 != nums1.end() || iter2 != nums2.end()){
            res.push_back(lexicographical_compare(iter1, nums1.end(), iter2, nums2.end()) ? *iter2++ : *iter1++);
        }
    return res;
}

// review
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    vector<int> res;
    for (int i = max(0, k - m); i <= min(n, k); i++) {
        vector<int> temp1 = selectMax(nums1, i);
        vector<int> temp2 = selectMax(nums2, k - i);
        vector<int> temp;
        auto iter1 = temp1.begin(), iter2 = temp2.begin();
        while (iter1 != temp1.end() || iter2 != temp2.end()) {
            temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
        }
        if (res < temp) res = temp;
    }
    return res;
}

vector<int> selectMax(vector<int>& num, int k) {
    if (num.size() == k) return num;
    int n = num.size() - k;
    vector<int> res;
    for (int i = 0; i < num.size(); i++) {
        while (!res.empty() && res.back() < num[i] && n > 0) {
            res.pop_back();
            n--;
        }
        res.push_back(num[i]);
    }

    while (n--) {
        res.pop_back();
    }

    return res;
}