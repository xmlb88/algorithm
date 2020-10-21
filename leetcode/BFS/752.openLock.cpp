#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

// int openLock(vector<string>deadends, string target) {

// }

// 穷举所有可能的密码组合

// 将s[j]向上拨动一次
string plusOne(string s, int j) {
    string res = s;
    if (res[j] == '9') {
        res[j] = '0';
    } else res[j] += 1;

    return res;
}

// 将s[j]向下拨动一次
string minusOne(string s, int j) {
    string res = s;
    if (res[j] == '0') {
        res[j] = '9';
    } else res[j] -= 1;

    return res;
}

// BFS框架，打印所有可能的密码
int main(string target) {
    queue<string> q;
    q.push("0000");

    while (!q.empty()) {
        int sz = q.size();
        // 将当前队列中的所有节点向周围扩散
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            // 在这里判断是否到达终点
            cout << cur << endl;

            // 将一个节点的相邻节点加入队列
            for (int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                string down = minusOne(cur, j);
                q.push(up);
                q.push(down);
            }
        }
        // 在这里增加步数
    }
    return 0;
}


// 加上终止条件和deadends处理，加上visited
string plusOne(string s, int j) {
    string res = s;
    if (res[j] == '9') res[j] = '0';
    else res[j] += 1;

    return res;
}

string minusOne(string s, int j) {
    string res = s;
    if (res[j] == '0') res[j] = '9';
    else res[j] -= 1;

    return res;
}

int openLock(vector<string> deadends, string target) {
    // 记录要跳过的死亡密码
    set<string> deads;
    for (string s : deadends) {
        deads.insert(s);
    }

    // 记录已经穷举过的密码，防止走回头路
    set<string> visited;
    queue<string> q;

    // 从起点开始启动广度优先搜索
    int step = 0;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();

            // 判断是否到达死亡密码
            if (deads.find(cur) != deads.end()) {
                continue;
            }
            // 判断是否到达终点
            if (cur == target) {
                return step;
            }

            // 将一个节点的未遍历相邻节点加入队列
            for (int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                if (visited.find(up) == visited.end()) {
                    q.push(up);
                    visited.insert(up);
                }

                string down = minusOne(cur, j);
                if (visited.find(down) == visited.end()) {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        // 在这里增加步数
        step++;
    }
    return -1;
}