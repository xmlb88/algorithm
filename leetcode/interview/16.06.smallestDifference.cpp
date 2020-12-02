#include <iostream>
#include <vector>
using namespace std;

// violence
int smallestDifference(vector<int>& a, vector<int>& b) {
    long long diff = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            long long temp = abs((long long)a[i] - (long long)b[j]);
            diff = min(diff, temp);
        }
    }
    return (int)diff;
}

// ÅÅÐò + Ë«Ö¸Õë±éÀú
int smallestDifference(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long diff = INT_MAX;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] >= b[j]) {
            diff = max(diff, (long long)a[i] - (long long)b[j]);
            j++;
        } else {
            diff = max(diff, (long long)b[j] - (long long)a[i]);
            i++;
        }
    }
    return (int)diff;
}