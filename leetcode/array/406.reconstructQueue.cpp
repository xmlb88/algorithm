#include <iostream>
#include <list>
#include <vector>
using namespace std;

// static bool cmp(vector<int> a, vector<int> b) {
//     if (a[0] == b[0]) return a[1] < b[1];
//     return a[0] < b[0];
// }
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b )
                                        {return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];});
    list<vector<int>> que;

    for (auto vec : people) {
        auto pos = que.begin();
        advance(pos, vec[1]);
        que.insert(pos, vec);
    }

    vector<vector<int>> res(que.begin(), que.end());
    return res;
}

// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// [7, 0]  [7, 1]  [6, 1]  [5, 0]  [5, 2]  [4, 4]

// [5, 0]  [7, 0]  [5, 2]  [6, 1]  [4, 4]  [7, 1]

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b)
                                        {return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];});

    vector<vector<int>> res;
    for(auto& vec : people) {
        res.insert(res.begin() + vec[1], vec);
    }
    return res;
}