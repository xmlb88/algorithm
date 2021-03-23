#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> val;
    int index = 0;

    void dfs(const vector<NestedInteger>& nestedList) {
        for (auto& nest : nestedList) {
            if (nest.isInteger()) {
                val.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }
public:
    
    NestedIterator(vector<NestedInteger>& nestedList) {
        dfs(nestedList);
    }

    int next() {
        return val[index++];
    }

    bool hasNext() {
        return index < val.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
private:
    vector<int> val;
    vector<int>::iterator it;

    void dfs(const vector<NestedInteger>& nestedList) {
        for (const auto& nest : nestedList) {
            if (nest.isInteger()) {
                val.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        dfs(nestedList);
        it = val.begin();
    }

    int next() {
        return *it++;
    }

    int hasNext() {
        return it != val.end();
    }
};


// 使用栈
class NestedIterator {
private:
    // pair 中存储的是列表当前遍历位置，以及一个尾后迭代器用于判断是否到了列表末尾
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        // 由于保证调用next之前会用hasNext，
        // 直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        return *stk.top().first++.getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto& p = stk.top();
            if (p.first == p.second) {
                return false;
            }

            if (p.first -> isInteger()) {
                return true;
            }

            auto& lst = p.first++ -> getList();
            stk.emplace(lst.begin(), lst.end());
        }

        return false;
    }
};