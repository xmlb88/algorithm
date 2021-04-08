#include <iostream>
#include <vector>
#include <set>
using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<int> ans;
    SummaryRanges() {

    }
    
    void addNum(int val) {
        ans.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int left = *ans.begin(), right = *ans.begin();
        for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (*it > right + 1) {
                res.push_back({left, right});
                left = *it;
            }
            right = *it;
        }
        res.push_back({left, right});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */