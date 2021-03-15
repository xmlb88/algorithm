#include <iostream>
#include <vector>
using namespace std;

// violence
vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) return {};
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[i]) ++num;
        }
        res.push_back(num);
    }
    return res;
}

// πÈ≤¢
// nums: 5 2 6 1
// index : 0 1 2 3
// res:
vector<int> index;
vector<int> temp;
vector<int> itemp;
vector<int> res;
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    temp.clear();
    itemp.clear();

    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            itemp.push_back(index[i]);
            res[index[i]] += j - (mid + 1);
            i++;
            continue;
        }

        temp.push_back(nums[j]);
        itemp.push_back(index[j]);
        j++;
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        itemp.push_back(index[i]);
        res[index[i]] += j - (mid + 1);
        i++;
    }

    while (j <= right) {
        temp.push_back(nums[j]);
        itemp.push_back(index[j]);
        j++;
    }

    copy(temp.begin(), temp.end(), nums.begin() + left);
    copy(itemp.begin(), itemp.end(), index.begin() + left);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    index.resize(n);
    iota(index.begin(), index.end(), 0);
    res.resize(n, 0);
    mergeSort(nums, 0, n - 1);
    return res;
}

//  π”√pair
vector<int> res;
vector<int> countSmaller(vector<int>& vec) {
    if (vec.empty()) return {};

    vector<pair<int, int>> nums;
    for (int i = 0; i < vec.size(); i++) {
        nums.emplace_back(vec[i], i);
    }

    res.resize(vec.size(), 0);
    merge_sort(nums, 0, nums.size() - 1);
    return res;
}

void merge_sort(vector<pair<int, int>>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void merge(vector<pair<int, int>>& nums, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<pair<int, int>> sort_nums;

    while (i <= mid && j <= right) {
        if (nums[i].first <= nums[j].first) {
            res[nums[i].second] += j - mid - 1;
            sort_nums.push_back(nums[i++]);
            continue;
        }

        sort_nums.push_back(nums[j++]);
    }

    while (i <= mid) {
        res[nums[i].second] += j - mid - 1;
        sort_nums.push_back(nums[i++]);
    }

    while (j <= right) {
        sort_nums.push_back(nums[j++]);
    }

    copy(sort_nums.begin(), sort_nums.end(), nums.begin() + left);
}