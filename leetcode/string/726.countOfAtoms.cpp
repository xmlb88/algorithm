#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

string getAtom(string& formula, int& i) {
    string atom;
    atom.push_back(formula[i++]);
    if (i < formula.size() && islower(formula[i])) {
        atom.push_back(formula[i]);
        ++i;
    }
    return atom;
}

int getCount(string& formula, int& i) {
    int num = 0;
    while (i < formula.size() && isdigit(formula[i])) {
        num = num * 10 + (formula[i] - '0');
        ++i;
    }

    return num == 0 ? 1 : num;
}

string countOfAtoms(string formula) {
    int i = 0, n = formula.size();
    stack<map<string, int>> st;
    st.push({});
    while (i < n) {
        if (formula[i] == '(') {
            st.push({});
            ++i;
        } else if (formula[i] == ')') {
            ++i;
            int outNum = getCount(formula, i);
            auto map = st.top();
            st.pop();
            for (auto& [c, count] : map) {
                st.top()[c] += count * outNum;
            }
        } else {
            string atom = getAtom(formula, i);
            int num = getCount(formula, i);
            st.top()[atom] += num;
        }
    }

    string res;
    auto m = st.top();
    for (auto& [c, count] : m) {
        res += c;
        if (count > 1) res += to_string(count);
    }
    return res;
}

int main() {
    string formula = "K4(ON(SO3)2)2";
    cout << countOfAtoms(formula) << endl;
}