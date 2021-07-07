#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int num = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            ++left;
        }
        --right;
        ++num;
    }
    return num;
}