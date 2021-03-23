#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> vec{
        "the",
        "apple",
        "xmlb",
        "dad",
        "zhang",
        "zhang"
        "shi",
        "jun"
    };

    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    // 345
}