#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    for (int i = 0; i < n; ++i) {
        if (citations[i] >= n - i) return n - i;
    }
    return 0;
}


int hIndex(vector<int>& citations) {
    int n = citations.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= n - mid) {
            right = mid - 1;
        } else left = mid + 1;
    }

    return n - left;
}

int main() {
    vector<int> citations = {0};
    cout << hIndex(citations) << endl;
}