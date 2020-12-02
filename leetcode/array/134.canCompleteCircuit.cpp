#include <iostream>
#include <vector>
using namespace std;

// own thought
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> sub;
    int sum;
    for (int i = 0; i < gas.size(); i++) {
        sub.push_back(gas[i] - cost[i]);
        sum += sub[i];
    }

    if (sum < 0) return -1;
    return start(sub);
}

int start(vector<int>& sub) {
    for (int i = 0; i < sub.size(); i++) {
        int gas_sum = 0;
        bool can_complete = true;
        for (int j = 0; j < sub.size(); j++) {
            int index = (i + j) % sub.size();
            gas_sum += sub[index];
            if (gas_sum < 0) {
                can_complete = false;
                break;
            }
        }
        if (can_complete) return i;
    }
    return -1;
}

// gas [1, 2, 3, 4, 5]
// cost[3, 4, 5, 1, 2]
// sub [-2, -2, -2, 3, 3]

// gas [5, 1, 2, 3, 4]
// cost[4, 4, 1, 5, 1]
// sub [1, -3, 1, -2, 3]

// Ò»´Î±éÀú
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int min_gas = INT_MAX;
    int get_gas = 0;
    int min_index = -1;
    for (int i = 0; i < gas.size(); i++) {
        get_gas += gas[i] - cost[i];
        if (get_gas < min_gas) {
            min_gas = get_gas;
            min_index = i;
        }
    }
    return get_gas >= 0 ? (min_index + 1) % gas.size() : -1;
}

// another way
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int left = 0, start = 0, total_gas = 0, total_cost = 0;
    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        left += gas[i] - cost[i];
        if (left < 0) {
            start = i + 1;
            left = 0;
        }
    }

    return total_gas >= total_cost ? start : -1;
}