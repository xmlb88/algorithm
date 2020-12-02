#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> temp;
    for (int i = 0; i < m; i++) {
        vector<int> vec;
        for (int j = n - 1; j >= 0; j--) {
            vec.push_back(matrix[j][i]);
        }
        temp.push_back(vec);
    }
    matrix = temp;
}

// ���ھ����е� i �еĵ� j ��Ԫ�أ�����ת���������ڵ����� i �еĵ� j ��λ�á�
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    auto matrix_new = matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix_new[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = matrix_new;
}

// matrix[x][y]                  =  matrix[n - y - 1][x]
// matrix[n - y - 1][x]          =  matrix[n - x - 1][n - y - 1]
// matrix[n - x - 1][n - y - 1]  =  matrix[y][n - x - 1]
// matrix[y][n - x - 1]          =  matrix[x][y]
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

// ��ˮƽ��ת���ٶԽ��߷�ת
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}