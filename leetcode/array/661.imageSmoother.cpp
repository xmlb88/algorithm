#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const vector<pair<int, int>> neighbor{{-1, -1}, {-1, 0}, {-1, 1},
{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<vector<int>> imageSmoother(vector<vector<int>>& image) {
    int n = image.size(), m = image[0].size();
    vector<vector<int>> newImage(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int total = image[i][j];
            int count = 1;
            int new_x, new_y;
            for (auto& offset : neighbor) {
                new_x = i + offset.first;
                new_y = j + offset.second;

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                    count++;
                    total += image[new_x][new_y];
                }
            }

            newImage[i][j] = floor(total / count);
        }
    }
    return newImage;
}


vector<vector<int>> imageSmoother(vector<vector<int>>& image) {
    int n = image.size(), m = image[0].size();
    vector<vector<int>> res(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int total = 0, count = 0;
            for (int p = i - 1; p <= i + 1; ++p) {
                if (p >= 0 && p < n) {
                    for (int q = j - 1; q <= j + 1; ++q) {
                        if (q >= 0 && q < m) {
                            count++;
                            total += image[p][q];
                        }
                    }
                }
            }
            res[i][j] = floor(total / count);
        }
    }
    return res;
}