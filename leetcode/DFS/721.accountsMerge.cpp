#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// class unionFind {
// private:
//     vector<int> f;
// public:
//     unionFind(int n) {
//         f.resize(n);
//         iota(f.begin(), f.end(), 0);
//     }

//     int find(int x) {
//         if (f[x] == x) return x;
        
//         f[x] = find(f[x]);
//         return f[x];
//     }

//     void unionSet(int x, int y) {
//         int fx = find(x), fy = find(y);
//         if (fx == fy) return;
//         f[fy] = fx;
//     }
// };

// vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//     unordered_map<string, int> emailToIndex;
//     unordered_map<string, string> emailToName;
//     int emailsCount = 0;
//     for (const vector<string>& account : accounts) {
//         string name = account[0];
//         int size = account.size();
//         for (int i = 1; i < size; i++) {
//             if (!emailToIndex.count(account[i])) {
//                 emailToIndex[account[i]] = emailsCount++;
//                 emailToName[account[i]] = name;
//             }
//         }
//     }

//     unionFind uf(emailsCount);
//     for (const vector<string>& account : accounts) {
//         string firstEmail = account[1];
//         int firstIndex = emailToIndex[firstEmail];
//         int size = account.size();
//         for (int i = 2; i < size; i++) {
//             string nextEmail = account[i];
//             int nextIndex = emailToIndex[nextEmail];
//             uf.unionSet(firstIndex, nextIndex);
//         }
//     }

//     unordered_map<int, set<string>> indexToEmails;
//     for (auto it = emailToIndex.begin(); it != emailToIndex.end(); it++) {
//         int index = uf.find(it -> second);
//         indexToEmails[index].insert(it -> first);
//     }

//     vector<vector<string>> merged;
//     for (auto& [index, emails] : indexToEmails) {
//         string name = emailToName[*emails.begin()];
//         vector<string> account;
//         account.push_back(name);
//         for (auto& email : emails) {
//             account.push_back(email);
//         }
//         merged.push_back(account);
//     }
//     return merged;
// }


// 方法1
// class unionFind {
// private:
//     vector<int> f;
// public:
//     unionFind(int n) {
//         f.resize(n);
//         iota(f.begin(), f.end(), 0);
//     }

//     int find(int x) {
//         if (f[x] == x) return x;
//         f[x] = find(f[x]);
//         return f[x];
//     }

//     void unionSet(int x, int y) {
//         int fx = find(x), fy = find(y);
//         if (fx == fy) return;
//         f[fy] = fx;
//     }
// };

// vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//     unordered_map<string, int> emailToIndex;
//     unordered_map<string, string> emailToName;
//     int emailsCount = 0;

//     for (auto& account : accounts) {
//         string name = account[0];
//         int size = account.size();
//         for (int i = 1; i < size; i++) {
//             if (emailToIndex.find(account[i]) == emailToIndex.end()) {
//                 emailToIndex[account[i]] = emailsCount++;
//                 emailToName[account[i]] = name;
//             }
//         }
//     }

//     unionFind uf(emailsCount);
//     for (auto& account : accounts) {
//         string firstEmail = account[1];
//         int firstIndex = emailToIndex[firstEmail];
//         int size = account.size();
//         for (int i = 2; i < size; i++) {
//             string nextEmail = account[i];
//             int nextIndex = emailToIndex[nextEmail];
//             uf.unionSet(firstIndex, nextIndex);
//         }
//     }

//     unordered_map<int, set<string>> indexToEmails;
//     for (auto it = emailToIndex.begin(); it != emailToIndex.end(); it++) {
//         int index = uf.find(it -> second);
//         indexToEmails[index].insert(it -> first);
//     }

//     vector<vector<string>> res;
//     for (auto [index, emails] : indexToEmails) {
//         string name = emailToName[*emails.begin()];
//         vector<string> account;
//         account.push_back(name);
//         for (auto email : emails) {
//             account.push_back(email);
//         }
//         res.push_back(account);
//     }
//     return res;
// }

// 方法二
class unionFind {
private:
    vector<int> f;
public:
    unionFind(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) return x;
        f[x] = find(f[x]);
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        f[fy] = fx;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
    vector<vector<string>> res;
    unordered_map<string, int> um;
    int n = accounts.size();
    unionFind uf(n);
    for (int i = 0; i < n; i++) {
        int m = accounts[i].size();
        for (int j = 1; j < m; j++) {
            string s = accounts[i][j];
            if (um.find(s) == um.end()) {
                um[s] = i;
            } else {
                uf.unionSet(i, um[s]);
            }
        }
    }

    unordered_map<int, set<string>> indexToEmail;
    for (auto& [k, v] : um) {
        int index = uf.find(v);
        indexToEmail[index].insert(k);
    }

    for (auto& [k, v] : indexToEmail) {
        string name = accounts[k][0];
        vector<string> account;
        account.push_back(name);
        for (auto& email : v) {
            account.push_back(email);
        }
        res.push_back(account);
    }
    return res;
}

// dfs
vector<vector<string>> res;
unordered_map<string, int> um;
vector<string> mails;
int emailsCount = 0;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    for (auto ac : accounts) {
        for (int i = 1; i < ac.size(); i++) {
            if (um.find(ac[i]) == um.end()) {
                mails.emplace_back(ac[i]);
                um[ac[i]] = emailsCount++;
            }
        }
    }

    vector<vector<int>> g(emailsCount);
    for (auto& ac : accounts) {
        for (int i = 1; i < ac.size(); i++) {
            for (int j = i + 1; j < ac.size(); j++) {
                int idxI = um[ac[i]], idxJ = um[ac[j]];
                g[idxI].push_back(idxJ);
                g[idxJ].push_back(idxI);
            }
        }
    }

    vector<bool> visited(emailsCount);
    for (auto& ac : accounts) {
        vector<string> cur(1, ac[0]);
        if (ac.size() < 1) continue;
        if (!visited[um[ac[1]]]) {
            dfs(g, um[ac[1]], visited, cur);
            sort(cur.begin() + 1, cur.end());
            res.push_back(cur);
        }
    }
    return res;
}

void dfs(vector<vector<int>>& g, int idx, vector<bool>& visited, vector<string>& cur) {
    visited[idx] = true;
    cur.push_back(mails[idx]);
    for (auto& nei : g[idx]) {
        if (!visited[nei]) dfs(g, nei, visited, cur);
    }
}