#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(string text, int w, int h, int fontSize, FontInfo fontInfo) {
    if (fontInfo.getHeight(fontSize) > h) return false;

    int sum_w = 0;
    for (char c : text) {
        sum_w += fontInfo.getWidth(fontSize, c);
        if (sum_w > w) return false;
    }
    return true;
}

int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
    int left = 0, right = fonts.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(text, w, h, fonts[mid], fontInfo)) {
            left = mid + 1;
        } else right = mid;
    }

    if (left == 0) return -1;
    return fonts[left - 1];
}

// TODO: