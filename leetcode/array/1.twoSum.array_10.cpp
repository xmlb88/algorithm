#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// �����ⷨ ʱ��O(n^2) �ռ�O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// ��ϣ�� ʱ��O(n) �ռ�O(n)
// ע���Լ������ظ�
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end() && i != map[target - nums[i]]) {
            return {i, map[target - nums[i]]};
        }
    }

    return {};
}

// ���� + ˫ָ�� ʱ��O(nlogn) �ռ�O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    // ��Ҫ����ԭ�����±���Ϣ
    // unordered_map<int, int> map;
    // for (int i = 0; i < nums.size(); i++) {
    //     map[nums[i]] = i;
    // }
    // ʹ��map����(3, 3) target = 6�����, ����{1, 1}
    vector<int> tmp = nums;
    int left = -1, right = -1;

    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            for (int k = 0; k < tmp.size(); k++) {
                if (tmp[k] == nums[i] || tmp[k] == nums[j]) {
                    if (left == -1) left = k;
                    else right = k;
                }
            }
            if (left > right) swap(left, right);
            return {left, right};
        } else if (nums[i] + nums[j] > target) j--;
        else if (nums[i] + nums[j] < target) i++;
    }
    return {};
}

// ��ϣ����һ�� ʱ��O(n) �ռ�O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i) {
            return {map[target - nums[i]], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// ���� + ˫ָ��, ��ȥ��ͬԪ��, ����Ԫ�ص�ֵ, ���, �����ظ�
vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int left = nums[i], int right = nums[j];
        int sum = left + right;
        if (sum < target) {
            while (i < j && nums[i] == left) i++;
        }
        else if (sum > target) {
            while (i < j && nums[j] == right) j--;
        }
        else if (sum == target) {
            res.push_back({i, j});
            // i++; j--; �����ظ�Ԫ��
            while (i < j && nums[i] == left) i++;
            while (i < j && nums[j] == right) j--;
        }
    }
    return res;
}



// twosum review 
// 2021��5��25��11:15:34
// ����ѭ��
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

// ��ϣ
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(target - nums[i]) != m.end()) {
            return {m[target - nums[i]], i};
        }
        m[nums[i]] = i;
    }
    return {-1, -1};
}

// ���� + ˫ָ��
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }

    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            return {m[nums[i]], m[nums[j]]};
        } else if (nums[i] + nums[j] < target) {
            ++i;
        } else --j;
    }
    return {-1, -1};
}