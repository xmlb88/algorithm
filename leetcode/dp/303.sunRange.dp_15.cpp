
// Ç°×ººÍ
class NumArray{
private:
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        presum.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return presum[j + 1] - presum[i];
    }
};

// nums = [-2, 0, 3, -5, 2, -1]
// presum = [0, -2, -2, 1, -4, -2, -3];
// i = 0, j = 2
// presum[3] - presum[0] = 1