#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
using namespace std;

map<string, string> buildMap(ifstream& map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && get_line(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

void word_transform(ifstream& map_file, ifstream& input) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}