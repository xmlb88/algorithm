#include <iostream>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> box;
    int max_num = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
        int sum = 0, num = i;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        box[sum]++;
        max_num = max(max_num, box[sum]);
    }
    return max_num;
}

// TODO:

int main() {
    cout << countBalls(1, 10) << endl;
}
