#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0, count = 0;
    while (i < flowerbed.size()) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i + 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i - 1] == 0)) {
            count++;
            flowerbed[i] = 1;
        }
        if (count >= n) return true;
        i++;
    }
    return count >= n;
}