#include <iostream>
#include <vector>
using namespace std;

// �ݹ�
vector<vector<int>> subsets(vector<int>& nums) {
    // base case
    if (nums.empty()) return {{}};
    // �����һ��Ԫ���ó���
    int n = nums.back();
    nums.pop_back();
    // �ȵݹ����ǰ��Ԫ�ص������Ӽ�
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
        // ��֮ǰ�Ľ����׷��
        res.push_back(res[i]);
        res.back().push_back(n);
    }

    return res;
}

// ����
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    for (int i = start; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track);
        track.pop_back();
    }
}