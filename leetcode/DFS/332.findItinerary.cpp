#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<string> findItinerary(vector<vector<string>>& tickets) {
    int n = tickets.size();
    vector<string> flight{"JFK"};
    vector<bool> used(n, false);
    dfs(tickets, flight, used);
    return res;
}

void dfs(vector<vector<string>>& tickets, vector<string> flight, vector<bool> used) {
    int n = tickets.size();
    if (flight.size() == n && find(used.begin(), used.end(), false) = used.end()) {
        if (res.empty() || flight < res) {
            res = flight;
        }
        return;
    } else if (flight.size() >= n) return;

    string last = flight.back();
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (tickets[i][0] == last) {
            flight.push_back(tickets[i][1]);
            used[i] = true;
            dfs(tickets, flight, used);
            flight.pop_back();
            used[i] = false;
        }
    }
}