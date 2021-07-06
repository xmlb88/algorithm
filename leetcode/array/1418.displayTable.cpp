#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> res;
    vector<string> colName;
    colName.push_back("Table");
    set<string> foodName;
    map<int, unordered_map<string, int>> m;
    for (auto& order : orders) {
        m[stoi(order[1])][order[2]]++;
        foodName.insert(order[2]);
    }
    for (auto& fname : foodName) {
        colName.emplace_back(fname);
    }
    res.push_back(colName);
    for (auto& p : m) {
        vector<string> row;
        row.push_back(to_string(p.first));
        for (int i = 1; i < colName.size(); ++i) {
            row.push_back(to_string(p.second[colName[i]]));
        }
        res.push_back(row);
    }
    return res;
}
