#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// vector<string> RPN;
// void transRPN(const string& s) {
//     int i = 0;
//     int num = 0;
//     stack<char> ops_stk;
//     unordered_map<char, int> mp {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}, {')', 3}};
//     while (i < s.size()) {
//         if (mp.find(s[i]) != mp.end()) {
//             if (s[i] == ')') {
//                 while (ops_stk.top() != '(') {
//                     RPN.push_back(string(1, ops_stk.top()));
//                     ops_stk.pop();
//                 }
//                 ops_stk.pop(); // pop '('
//                 ++i;
//                 continue;
//             }

//             if (s[i] == '(') {
//                 ops_stk.push(s[i]);
//                 ++i;
//                 continue;
//             }

//             while (!ops_stk.empty() && mp[ops_stk.top()] >= mp[s[i]] && ops_stk.top() != '(') {
//                 RPN.push_back(string(1, ops_stk.top()));
//                 ops_stk.pop();
//             }
//             ops_stk.push(s[i]);
//             ++i;
//         } else {
//             while (isdigit(s[i])) {
//                 num = num * 10 + (s[i] - '0');
//                 ++i;
//             }
//             RPN.push_back(to_string(num));
//             num = 0;
//         }
//     }

//     while (!ops_stk.empty()) {
//         RPN.push_back(string(1, ops_stk.top()));
//         ops_stk.pop();
//     }
// }

// int evalRPN() {
//     stack<int> stk;
//     for (const string& str : RPN) {
//         if (str == "+" || str == "-" || str == "*" || str == "/") {
//             int num1 = stk.top(); stk.pop();
//             int num2 = stk.top(); stk.pop();
//             if (str == "+") {
//                 stk.push(num2 + num1);
//                 continue;
//             }

//             if (str == "-") {
//                 stk.push(num2 - num1);
//                 continue;
//             }

//             if (str == "*") {
//                 stk.push(num2 * num1);
//                 continue;
//             }

//             if (str == "/") {
//                 stk.push(num2 / num1);
//                 continue;
//             }
//         } else {
//             stk.push(stoi(str));
//         }
//     }
//     return stk.top();
// }

// int calculate(string s) {
//     transRPN(s);
//     return evalRPN();
// }


// review 2021Äê3ÔÂ12ÈÕ10:31:44
vector<string> RPN;
void transRPN(const string& s) {
    stack<char> op_stk;
    unordered_map<char, int> mp{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(',3}, {')', 3}};
    int i = 0, num = 0;
    while (i < s.size()) {
        if (mp.find(s[i]) != mp.end()) {
            if (s[i] == '(') {
                op_stk.push(s[i]);
                ++i;
                continue;
            }

            if (s[i] == ')') {
                while (op_stk.top() != '(') {
                    RPN.push_back(string(1, op_stk.top()));
                    op_stk.pop();
                }
                op_stk.pop();
                ++i;
                continue;
            }

            while (!op_stk.empty() && mp[op_stk.top()] >= mp[s[i]] && op_stk.top() != '(') {
                RPN.push_back(string(1, op_stk.top()));
                op_stk.pop();
            }
            op_stk.push(s[i]);
            ++i;
        } else {
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            RPN.push_back(to_string(num));
            num = 0;
        }
    }

    while (!op_stk.empty()) {
        RPN.push_back(string(1, op_stk.top()));
        op_stk.pop();
    }
}

int evalRPN() {
    stack<int> st;
    for (const string& str : RPN) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            if (str == "+") {
                st.push(num2 + num1);
                continue;
            }

            if (str == "-") {
                st.push(num2 - num1);
                continue;
            }

            if (str == "*") {
                st.push(num2 * num1);
                continue;
            }

            if (str == "/") {
                st.push(num2 / num1);
                continue;
            }
        } else {
            st.push(stoi(str));
        }
    }
    return st.top();
}

int calculate(string s) {
    transRPN(s);
    return evalRPN();
}

int main() {
    string s = "2*(5+5*2)/3+(6/2+8)";
    cout << calculate(s) << endl;
}