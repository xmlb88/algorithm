#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(int a, int b) {
    int count_a = 0, tmp_a = a;
    while (a) {
        a &= (a - 1);
        count_a++;
    }

    int count_b = 0, tmp_b = b;
    while (b) {
        b &= (b - 1);
        count_b++;
    }
    if (count_a == count_b) return tmp_a < tmp_b;
    return count_a < count_b;
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}

int main() {
    vector<int> arr{1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> res = sortByBits(arr);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}




// 判断一个数多少个1
// 方法1
// int bitCount(int n) {
//     int count = 0;
//     while (n) {
//         if ((n & 1) == 1) count++; // 当前位是1
//         n >>= 1; // n向右移位
//     }
//     return count;
// }

// // 方法2 (更高效)
// int bitCount(int n) {
//     int count = 0;
//     while (n) {
//         n &= (n - 1); // 清除最低位的1
//         count++;
//     }
//     return count;
// }