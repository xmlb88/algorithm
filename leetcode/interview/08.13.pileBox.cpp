#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int pileBox(vector<vector<int>>& box) {
    int n = box.size();
    vector<bool> used(n, false);
    vector<vector<int>> usedBoxes;
    dfs(box, 0, used, usedBoxes);
    return res;
}

void dfs(vector<vector<int>>& box, int height, vector<bool>& used, vector<vector<int>>& usedBoxes) {
    bool flag = false;
    int n = box.size();
    for (int i = 0; i < box.size(); i++) {
        if (usedBoxes.empty()) {
            flag = true;
            height += box[i][2];
            usedBoxes.push_back(box[i]);
            used[i] = true;
            dfs(box, height, used, usedBoxes);
            height -= box[i][2];
            usedBoxes.pop_back();
            used[i] = false;
        } else if (!used[i]) {
            auto last_box = usedBoxes.back();
            if (box[i][0] > last_box[0] && box[i][1] > last_box[1] && box[i][2] > last_box[2]) {
                flag = true;
                height += box[i][2];
                usedBoxes.push_back(box[i]);
                used[i] = true;
                dfs(box, height, used, usedBoxes);
                height -= box[i][2];
                usedBoxes.pop_back();
                used[i] = false;
            }
        }
    }
    if (!flag) {
        res = max(res, height);
        return;
    }
}