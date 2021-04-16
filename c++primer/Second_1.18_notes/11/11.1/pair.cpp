#include <iostream>
#include <utility>
using namespace std;

pair<string, string> author = {"James", "Joyce"};
// int main() {
//     cout << author.first << " " << author.second << endl;
// }

pair<string, int> precess(vector<string>& v) {
    /* 
    if (!v.empty()) {
        retuurn pair<string, int>(v.back(), b.back().size());
    }
     */
    if (!v.empty()) {
        return {v.back(), v.back.size()};
        // return make_pair(v.back(), b.back().size());
    } else {
        return pair<string, int> ();
    }
}