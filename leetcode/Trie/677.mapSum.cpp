#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class MapSum {
private:
    vector<MapSum*> next;
    int val = 0;
    int preSum = 0;

    MapSum* getPrefix(string prefix) {
        MapSum* node = this;
        for (char c : prefix) {
            c = c - 'a';
            if (node->next[c] == nullptr) {
                return nullptr;
            }
            node = node->next[c];
        }
        return node;
    }

public:
    MapSum() : next(26) {

    }

    void insert(string key, int val) {
        MapSum* node = this;
        MapSum* oldNode = getPrefix(key);
        int oldVal = 0;
        if (oldNode != nullptr) {
            oldVal = oldNode->val;
        }

        for (char c : key) {
            c = c - 'a';
            if (node->next[c] == nullptr) {
                node->next[c] = new MapSum();
            }
            node->preSum += val - oldVal;
            node = node->next[c];
        }
        node->preSum += val - oldVal;
        node->val = val;
    }

    int sum(string prefix) {
        MapSum* node = getPrefix(prefix);
        return node ? node->preSum : 0;
    }
};


// https://leetcode-cn.com/problems/map-sum-pairs/solution/zi-dian-shu-dfs-by-hw_wt-18du/
//

struct Trie {
    vector<Trie*> next;
    bool isEnd;
    int val;

    Trie() : next(26), isEnd(false), val(0) {}
};

class MapSum {
public:
    Trie root;

    MapSum() {

    }

    void insert(const string& key, int val) {
        Trie* cur = &root;

        for (char c : key) {
            c = c - 'a';
            if (cur->next[c] == nullptr) {
                cur->next[c] = new Trie();
            }
            cur = cur->next[c];
        }
        cur->isEnd = true;
        cur->val = val;
    }

    void dfs(Trie* root, int& ans) {
        if (root->isEnd) {
            ans += root->val;
        }

        for (Trie* node : root->next) {
            if (node) dfs(node, ans);
        }
    }

    int sum(const string& prefix) {
        Trie* cur = &root;
        int ans = 0;

        for (char c : prefix) {
            c = c - 'a';
            if (cur->next[c] == nullptr) {
                return 0;
            }
            cur = cur->next[c];
        }

        dfs(cur, ans);
        return ans;
    }
};