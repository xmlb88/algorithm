#include <iostream>
#include <vector>
using namespace std;

// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//     vector<pair<int, int>> arrDis;
//     for (auto& num : arr) {
//         arrDis.emplace_back(num, abs(x - num));
//     }

//     sort(arrDis.begin(), arrDis.end(), [](const pair<int, int>& a, const pair<int, int>& b){
//         if (a.second == b.second) return a.first < b.first;
//         return a.second < b.second;
//     });

//     vector<int> res;
//     for (int i = 0; i < k; ++i) {
//         res.push_back(arrDis[i].first);
//     }
//     sort(res.begin(), res.end());
//     return res;
// }

// // 左右开始，剔除
// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//     int n = arr.size();
//     int left = 0, right = n - 1;
//     while (right - left + 1 > k) {
//         if (abs(arr[right] - x) >= abs(arr[left] - x)) {
//             --right;
//         } else {
//             ++left;
//         }
//     }
//     return vector<int> (arr.begin() + left, arr.begin() + right + 1);
// }

// 二分查找，再剔除
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    if (x <= arr[0]) return vector<int> (arr.begin(), arr.begin() + k);
    if (x >= arr[n - 1]) return vector<int> (arr.end() - k, arr.end());

    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    int left_index = max(0, left - k - 1);
    int right_index = min(n - 1, left + k - 1);
    while (right_index - left_index + 1 > k) {
        if (arr[right_index] - x >= x - arr[left_index]) {
            --right_index;
        } else {
            ++left_index;
        }
    }

    return vector<int> (arr.begin() + left_index, arr.begin() + right_index + 1);
}

int main() {
    vector<int> arr{0,0,1,2,3,3,4,7,7,8};
    findClosestElements(arr, 3, 5);
}