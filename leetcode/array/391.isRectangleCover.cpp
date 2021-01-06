#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) {
    set<pair<int, int>> points;
    vector<pair<int, int>> expect_points;

    int infact_area = 0;
    for (auto rectangle : rectangles) {
        pair<int, int> left_down = make_pair(rectangle[0], rectangle[1]);
        pair<int, int> right_up = make_pair(rectangle[2], rectangle[3]);
        
        // 求面积和
        infact_area += (right_up.first - left_down.first) * (right_up.second - left_down.second);

        // points保存顶点
        if (points.count(left_down)) points.erase(left_down);
        else (points.insert(left_down));

        if (points.count(right_up)) points.erase(right_up);
        else (points.insert(right_up));

        pair<int, int> left_up = make_pair(left_down.first, right_up.second);
        if (points.count(left_up)) points.erase(left_up);
        else (points.insert(left_up));

        pair<int, int> right_down = make_pair(right_up.first, left_down.second);
        if (points.count(right_down)) points.erase(right_down);
        else (points.insert(right_down));

        // expect_points保存最小和最大顶点
        if (expect_points.empty()) {
            expect_points.push_back(left_down);
            expect_points.push_back(right_up);
        } else {
            if (left_down.first < expect_points[0].first || 
               (left_down.first == expect_points[0].first && left_down.second < expect_points[0].second)) {
                   expect_points[0] = left_down;
               }

            if (right_up.first > expect_points[1].first || 
               (right_up.first == expect_points[1].first && right_up.second > expect_points[1].second)) {
                   expect_points[1] = right_up;
               }
        }
    }

    // 比较面积
    int expect_area = (expect_points[1].first - expect_points[0].first) * (expect_points[1].second - expect_points[0].second);
    if (expect_area != infact_area) return false;

    // 顶点长度
    if (points.size() != 4) return false;

    // 生成实际顶点
    expect_points.push_back(make_pair(expect_points[0].first, expect_points[1].second));
    expect_points.push_back(make_pair(expect_points[1].first, expect_points[0].second));

    // 比较顶点
    for (auto kv : expect_points) {
        if (!points.count(kv)) return false;
    }

    return true;
}

// 4 + 1 + 2 + 1 + 1 = 9

// expect_points = {[1, 1] [4, 4]}

// points = {[1, 1], [3, 3], [3, 1], [4, 2], [3, 2], [4, 4], [1, 3], [2, 4], [2, 3], [3, 4]}