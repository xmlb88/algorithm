#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // map<string, string> authors = {{"Joyce", "James"}, {"Austen", "Jane"}, {"Dickens", "Charles"}};
    // for (map<string, string>::iterator it = authors.begin(); it != authors.end(); ++it) {
    //     cout << it -> first << " --> " << it-> second << endl;
    // }
    multimap<string, string> m = {{"test", "alice"}, {"test", "nakiri"}};
    cout << m.size() << endl;
    // for (auto it = m.begin(); it != m.end(); ++it) {
    //     cout << it -> first << " --> " << it-> second << endl;
    // }
}