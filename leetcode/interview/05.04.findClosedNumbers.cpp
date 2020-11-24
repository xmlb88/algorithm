#include <iostream>
#include <vector>
using namespace std;

vector<int> findClosedNumbers(int num) {
    if (num == 1) {
        return {2, -1};
    }

    if (num == INT_MAX) {
        return {-1, -1};
    }


}