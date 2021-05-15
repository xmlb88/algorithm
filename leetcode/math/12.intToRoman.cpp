#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string intToRoman(int num) {
    vector<int> nums{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> rome{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    string s = "";
    int idx = nums.size() - 1;
    while (idx >= 0 && num > 0) {
        if (num >= nums[idx]) {
            s += rome[idx];
            num -= nums[idx];
        } else {
            --idx;
        }
    }
    return s;
}

string intToRoman(int num) {
    vector<pair<int, string>> valueSymbols = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string roman;
    for (const auto& [value, symbol] : valueSymbols) {
        while (num >= value) {
            num -= value;
            roman += symbol;
        }

        if (num == 0) break;
    }
    return roman;
}

// Ó²±àÂëÊý×Ö
const vector<string> thousands = {"", "M", "MM", "MMM"};
const vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string intToRoman(int num) {
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}