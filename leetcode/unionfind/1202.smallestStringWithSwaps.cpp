#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;
public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        // for (int i = 0; i < n; i++) {
        //     f[i] = i;
        // }
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        // return f[x] == x ? x : f[x] = find(f[x]);
        if (f[x] == x) {
            return x;
        } else {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSetUnion dsu(s.length());
        for (auto& it : pairs) {
            dsu.unionSet(it[0], it[1]);
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[dsu.find(i)].emplace_back(s[i]);
        }

        for (auto& [x, vec] : mp) {
            sort(vec.begin(), vec.end(), greater<int>());
        }

        for (int i = 0; i < s.length(); i++) {
            int x = dsu.find(i);
            s[i] = mp[x].back();
            mp[x].pop_back();
        }
        return s;
    }
};


class unionFind {
private:
    vector<int> f, rank;
    int n;
public:
    unionFind(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        } else {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }

        rank[fx] += rank[fy];
        f[fy] = fx;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unionFind uf(s.length());
        for (vector<int>& it : pairs) {
            uf.unionSet(it[0], it[1]);
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[uf.find(i)].emplace_back(s[i]);
        }

        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end(), greater<int>);
        }

        for (int i = 0; i < s.length(); i++) {
            int x = uf.find(i);
            s[i] = mp[x].back();
            mp[x].pop_back();
        }
        return s;
    }
};