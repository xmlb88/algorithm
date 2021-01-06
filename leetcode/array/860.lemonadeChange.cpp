#include <iostream>
#include <vector>
using namespace std;

// bool lemonadeChange(vector<int>& bills) {
//     int b_5 = 0, b_10 = 0, b_20 = 0;
//     for (int bill : bills) {
//         if (bill == 5) b_5++;
//         else if (bill == 10) b_10++;
//         else b_20++;
//     }

//     if (b_5 < b_10) return false;
//     b_5 = b_5 - b_10;
//     if (b_10 >= b_5) {
//         return b_5 >= b_20;
//     } else {
//         return (b_5 - b_10) / 3 >= (b_20 - b_10);
//     }
// }
//5 5 10 10 20
// b_5 = 2 b_10 = 2 b_20 = 1
// b_5 = 0 b_10 = 2 b_20 = 1

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five <= 0) return false;
            five--;
            ten++;
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                five--;
                ten--;
            } else if (ten == 0 && five >= 3) {
                five -= 3;
            } else return false;
        }
    }
    return true;
}