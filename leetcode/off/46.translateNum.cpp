#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO:
int translateNum(int num) {
    if (num == 0) return 1;
    return dfs(num);
}

int dfs(int num) {
    if (num < 10) {
        return 1;
    }

    if (num % 100 < 26 && num % 100 > 9) {
        return dfs(num / 100) + dfs(num / 10);
    } else return dfs(num / 10);
}