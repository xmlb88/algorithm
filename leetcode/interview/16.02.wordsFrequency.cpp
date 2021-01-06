#include <iostream>
#include <unordered_map>
using namespace std;

class WordsFrequency {
public:
    unordered_map<string, int> m;
    WordsFrequency(vector<string>& book) {
        for (string s : book) {
            m[s]++;
        }
    }
    
    int get(string word) {
        return m[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */