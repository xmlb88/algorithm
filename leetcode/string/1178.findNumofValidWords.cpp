#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    vector<int> res;
    for (auto puzzle : puzzles) {
        int num = 0;
        for (auto word : words) {
            if (isPuzzle(word, puzzle)) ++num;
        }
        res.push_back(num);
    }
    return res;
}

bool isPuzzle(const string& word, const string& puzzle) {
    unordered_set<char> word_s(word.begin(), word.end());
    unordered_set<char> puzzle_s(puzzle.begin(), puzzle.end());
    char first = puzzle[0];
    if (word_s.find(first) == word_s.end()) return false;

    for (char c : word) {
        if (puzzle_s.find(c) == puzzle_s.end()) return false;
    }
    return true;
}