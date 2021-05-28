#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
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


// review 2021年5月28日16:29:20
// dfs

unordered_map<string, vector<string>> graph;

void dfs(vector<string>& account, unordered_set<string>& visited, string mail) {
    if (visited.find(mail) != visited.end()) return;
    account.push_back(mail);
    visited.insert(mail);
    for (string neibor : graph[mail]) {
        dfs(account, visited, neibor);
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    for (auto& ac : accounts) {
        for (int i = 1; i < ac.size(); ++i) {
            for (int j = i + 1; j < ac.size(); ++j) {
                graph[ac[i]].push_back(ac[j]);
                graph[ac[j]].push_back(ac[i]);
            }
        }
    }

    vector<vector<string>> res;
    unordered_set<string> visited;
    for (auto& ac: accounts) {
        if (visited.find(ac[1]) == visited.end()) {
            vector<string> account;
            account.push_back(ac[0]);
            dfs(account, visited, ac[1]);
            sort(account.begin() + 1, account.end());
            res.push_back(account);
        }
    }
    return res;
}


// union-find
class unionFind {
    vector<int> parent;
    vector<int> rank;

    unionFind(int n) : parent(vector<int> (n)), rank(vector<int> (n)) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> res;
    
    // 存储每个邮箱属于哪个账户，同时，在遍历邮箱时，判断邮箱是否出现过
    // 格式：<邮箱，账户id>
    unordered_map<string, int> um;
    int n = accounts.size();
    unionFind uf(n);
    for (int i = 0; i < n; ++i) {
        int m = acc[i].size();
        for (int j = 1; j < m; ++j) {
            string s = accounts[i][j];
            if (um.find(s) == um.end()) {
                um[s] = i;
            } else {
                uf.merge(i, um[s]);
            }
        }
    }
    
    // 作用：存储每个账户下的邮箱
    // 格式：<账户id, 邮箱列表>
    // 注意：这里的key必须是账户id，不能是账户名称，名称可能相同，造成覆盖
    unordered_map<int, vector<string>> umv;
    for (auto& [k, v] : um) {
        umv[uf.find(v)].emplace_back(k);
    }

    for (auto& [k, v] : umv) {
        sort(v.begin(), v.end());
        vector<string> account(1, acc[k][0]);
        account.insert(account.end(), v.begin(), v.end());
        res.emplace_back(account);
    }
    return res;
}



// review 2021年5月28日19:47:01
// union-find

class unionFind {
private:
    vector<int> f, rank;
    int unionCount;
public:
    unionFind(int n) : f(n), rank(n, 1), unionCount(n) {
        // iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }

        f[fy] = fx;
        rank[fx] += rank[fy];
        --unionCount;
        return true;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    vector<vector<string>> res;

    unordered_map<string, int> um;
    unionFind uf(n);
    for (int i = 0; i < accounts.size(); ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            string mail = accounts[i][j];
            if (um.find(mail) == um.end()) {
                um[mail] = i;
            } else {
                uf.merge(i, um[mail]);
            }
        }
    }

    unordered_map<int, vector<string>> umv;
    for (auto& [k, v] : um) {
        umv[uf.find(v)].push_back(k);
    }

    for (auto& [k, v] : umv) {
        sort(v.begin(), v.end());
        vector<string> account(1, accounts[k][0]);
        for (auto& s : v) {
            account.push_back(s);
        }
        res.push_back(account);
    }
    return res;
}