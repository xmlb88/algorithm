#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (const string& str : tokens) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            int op_num1 = stk.top(); stk.pop();
            int op_num2 = stk.top(); stk.pop();
            if (str == "+") stk.push(op_num1 + op_num2);
            else if (str == "-") stk.push(op_num2 - op_num1);
            else if (str == "*") stk.push(op_num1 * op_num2);
            else if (str == "/") stk.push(op_num2 / op_num1);
        } else {
            stk.push(stoi(str));
        }
    }
    return stk.top();
}