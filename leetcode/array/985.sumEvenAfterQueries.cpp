#include <iostream>
#include <vector>
using namespace std;

// TLE
vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> res;
    for (auto& quer : queries) {
        int val = quer[0], index = quer[1];
        A[index] += val;

        int sum = 0;
        for (int a : A) {
            if (a & 1) continue;
            sum += a;
        }
        res.push_back(sum);
    }
    return res;
}

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    int sum_even = 0;
    for (int a : A) {
        if (a & 1) continue;
        sum_even += a;
    }

    vector<int> res;
    for (auto& quer : queries) {
        int val = quer[0], index = quer[1];
        if (!(A[index] & 1)) sum_even -= A[index];
        A[index] += val;
        if (!(A[index] & 1)) sum_even += A[index];
        res.push_back(sum_even);
    }
    return res;
}