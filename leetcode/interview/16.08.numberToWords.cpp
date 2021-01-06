#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<string> smalls = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", 
"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
"Seventy", "Eighty", "Ninety"};
vector<string> bigs = {"", "Thousand", "Million", "Billion"};
string hundred = "Hundred";
string negative = "Negative";

string numberToWords(int num) {
    if (num == 0) return smalls[0];
    else if (num < 0) return negative + " " + numberToWords(-1 * num);

    deque<string> parts;
    int chunkCount = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            string chunk;
            if (bigs[chunkCount].empty()) {
                chunk = convertChunk(num % 1000);
            } else chunk = convertChunk(num % 1000) + " " + bigs[chunkCount];
            parts.push_front(chunk);
        }
        num /= 1000;
        chunkCount++;
    }
    return toString(parts);
}

string convertChunk(int number) {
    deque<string> parts;

    // 转换百位
    if (number >= 100) {
        parts.push_back(smalls[number / 100]);
        parts.push_back(hundred);
        number %= 100;
    }

    // 转换十位
    if (number >= 10 && number <= 19) {
        parts.push_back(smalls[number]);
    } else if (number >= 20) {
        parts.push_back(tens[number / 10]);
        number %= 10;
    }

    // 转换个位
    if (number >= 1 && number <= 9) {
        parts.push_back(smalls[number]);
    }

    return toString(parts);
}

string toString(deque<string>& parts) {
    string sb;
    while (parts.size() > 1) {
        sb += parts.front();
        parts.pop_front();
        sb += " ";
    }
    sb += parts.front();
    return sb;
}