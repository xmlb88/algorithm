#include <iostream>
#include <vector>
using namespace std;

int calculate(int base_count, vector<int>& bucket, vector<int>& vat, vector<int>& times) {
    int n = bucket.size();
    int max_index = 0;
    int max_times = 0;
    for (int i = 0; i < n; ++i) {
        if (times[i] > max_times) {
            max_times = times[i];
            max_index = i;
        }
    }

    bucket[max_index] += 1;
    if (vat[max_index] % bucket[max_index] == 0) {
        times[max_index] = vat[max_index] / bucket[max_index];
    } else {
        times[max_index] = (vat[max_index] + bucket[max_index]) / bucket[max_index];
    }
    return base_count + 1 + *max_element(times.begin(), times.end());
}

int storeWater(vector<int>& bucket, vector<int>& vat) {
    int n = bucket.size();
    if (n == 0) return 0;
    vector<int> times(n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (bucket[i] == 0 && vat[i] == 0) {
            times[i] = 0;
            continue;
        } else if (bucket[i] == 0 && vat[i] > 0) {
            bucket[i] += 1;
            count += 1;
            times[i] = vat[i];
            continue;
        } else {
            if (vat[i] % bucket[i] == 0) {
                times[i] = vat[i] / bucket[i];
            } else {
                times[i] = (vat[i] + bucket[i]) / bucket[i];
            }
        }
    }

    int min_count = count + *max_element(times.begin(), times.end());
    int next_count = calculate(count, bucket, vat, times);
    while (next_count <= min_count) {
        min_count = next_count;
        next_count = calculate(count, bucket, vat, times);
    }
    return min_count;
}

// [1, 3], [6, 8]       [6, 3]
// [2, 3]               [3, 3]
// 1 6 6ci
// 2 6 3 + 1 = 4ci
// 3 6 2 + 2 = 4ci
// 4 6 2 + 3 = 5ci
// 5 6 2 + 4 = 6ci
// 6 6 1 + 5 = 6ci

// 3 8 3 + 0 = 3ci
// 4 8 2 + 1 = 3ci