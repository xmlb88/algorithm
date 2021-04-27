#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    std::default_random_engine e;   // ����
    std::normal_distribution<double> n(4, 1.5);
    std::vector<unsigned> vals(9);
    for (std::size_t i = 0; i != 200; ++i) {
        unsigned v = std::lround(n(e));
        if (v < vals.size())
            ++vals[v];
    }

    for (std::size_t j = 0; j != vals.size(); ++j) {
        std::cout << j << " : " << vals[j] << std::string(vals[j], '*') << std::endl;
    }

    int sum = std::accumulate(vals.begin(), vals.end(), 0);
    std::cout << "sum = " << sum << std::endl;
    return 0;
}