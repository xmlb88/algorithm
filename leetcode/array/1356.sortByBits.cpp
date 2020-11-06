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




// �ж�һ�������ٸ�1
// ����1
// int bitCount(int n) {
//     int count = 0;
//     while (n) {
//         if ((n & 1) == 1) count++; // ��ǰλ��1
//         n >>= 1; // n������λ
//     }
//     return count;
// }

// // ����2 (����Ч)
// int bitCount(int n) {
//     int count = 0;
//     while (n) {
//         n &= (n - 1); // ������λ��1
//         count++;
//     }
//     return count;
// }