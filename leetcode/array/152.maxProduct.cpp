#include <iostream>
#include <vector>
using namespace std;

// ���������Խ�������
// ��2�������¼���ֵ����Сֵ
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxF(n), minF(n);
    maxF[0] = nums[0], minF[0] = nums[0];
    for (int i = 1; i < n; i++) {
        maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
        minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}

// �Ż��ռ临�Ӷ�
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxF = nums[0], minF = nums[0], res = nums[0];
    for (int i = 1; i < n; i++) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(mn * nums[i], nums[i]));
        minF = min(mx * nums[i], min(mn * nums[i], nums[i]));
        res = max(res, maxF);
    }

    return res;
}