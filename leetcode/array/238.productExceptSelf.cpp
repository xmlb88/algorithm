#include <iostream>
#include <vector>
using namespace std;

// ������ʱ
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int p = 1;
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            p *= nums[j];
        }
        res[i] = p;
    }
    return res;
}

// pre last ���ҳ˻��б�
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n);
    pre[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i] * nums[i];
    }

    vector<int> last(n);
    last[n - 1] = 1;
    for (int i = n - 1; i >= 1; i--) {
        last[i - 1] = last[i] * nums[i];
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = pre[i] * last[i];
    }
    return res;
}
// [1,2,3,4]
// pre [1, 1, 2, 6]
// last [24, 12, 4, 1]

// �ó�������R�ұ߳˻�
// ����left���� ��Ϊ��
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);

    // �ȼ�����߳˻��б�
    res[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        res[i + 1] = res[i] * nums[i];
    }

    int r = 1; // ���������ұ߳˻�
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= r;
        r *= nums[i];
    }

    return res;
}