#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            vector<int> presum{0};
            for (int j = 0; j < m; ++j) {
                int back = presum.back();
                presum.push_back(back + matrix[i][j]);
            }
            preSum.push_back(presum);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (preSum.empty()) return 0;
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += preSum[i][col2 + 1] - preSum[i][col1];
        }
        return sum;
    }
};

// ����ǰ׺��
// ����preSum[i][j]��ʾ[0, 0]��[i, j]�ľ���Ԫ��֮��
// preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - 
//                  preSum[i - 1][j - 1] + matrix[i][j]

// ����[row1, col1] ��[row2, col2] �����
// sum = preSum[row2][col2] - preSum[row2][col1 - 1] - 
//       preSum[row1 - 1][col2] + preSum[row1 - 1][col1 - 1]

// ע�⣺preSumӦ�ö�һ��һ�У�Ϊ�˷������
// 1   2   3
// 4   5   6
// 7   8   9

// preSum:
// 0    0   0   0
// 0    1   3   6
// 0    5   12  21
// 0    12  27  45

class NumMatrix {
private:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        preSum.resize(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};