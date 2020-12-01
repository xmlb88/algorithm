#include <iostream>
#include <vector>
using namespace std;

// violence
int maxAliveYear(vector<int>& birth, vector<int>& death) {
    int n = birth.size();
    int maxAlive = 0, maxYear = 1900;
    vector<int> year(100, 0);
    for (int i = 0; i < 200; i++) {
        int alive = 0;
        for (int j = 0; j < n; j++) {
            if (birth[j] <= 1900 + i && death[j] >= 1900 + i) {
                alive++;
            }
        }

        if (alive > maxAlive) {
            maxAlive = alive;
            maxYear = i + 1900;
        }
    }
    return maxYear;
}

int maxAliveYear(vector<int>& birth, vector<int>& death) {
    vector<int> res(110, 0);
    int n = birth.size();
    for (int i = 0; i < n; i++) {
        res[birth[i] - 1900]++;
        res[death[i] - 1900 + 1]++;
    }

    int ans = res[0];
    int ret;
    for (int i = 1; i < 101; i++) {
        res[i] += res[i - 1];
        if (res[i] > ans) {
            ans = res[i];
            ret = i + 1900;
        }
    }

    return ret;
}