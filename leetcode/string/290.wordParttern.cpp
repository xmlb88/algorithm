#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

bool wordPattern(string pattern, string s) {
    int n = pattern.size();
    vector<string> svec = split(s);
    if (svec.size() != n) return false;
    unordered_map<char, string> ptos;
    unordered_map<string, char> stop;
    for (int i = 0; i < n; i++) {
        if (ptos.find(pattern[i]) != ptos.end() && ptos[pattern[i]] != svec[i]) return false;
        if (stop.find(svec[i]) != stop.end() && stop[svec[i]] != pattern[i]) return false;
        ptos[pattern[i]] = svec[i];
        stop[svec[i]] = pattern[i];
    }
    return true;
}

vector<string> split(string& s) {
    stringstream ss(s);
    vector<string> vec;
    string str;
    while (getline(ss, str, ' ')) {
        vec.push_back(str);
    }
    return vec;
}