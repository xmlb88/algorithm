#include <iostream>
#include <string>
#include <stack>
using namespace std;

// string removeDuplicates(string S) {
//     string s = S;
//     while (true) {
//         string temp;
//         int size = s.size();
//         for (int i = 0; i < size - 1; i++) {
//             if (s[i] == s[i + 1]) {
//                 i++;
//                 if (i == size - 1) {
//                     temp.push_back(i + 1);
//                 }
//                 continue;
//             }
//             if (i == size - 2) {
//                 temp.push_back(s[i]);
//                 temp.push_back(s[i + 1]);
//             } else {
//                 temp.push_back(s[i]);
//             }
//         }
//         if (temp.size() == s.size() || temp.size() == 0) return temp;
//         else s = temp;
//     }

//     return "";
// }

// int main() {
//     string s = "azxxzy";
//     cout << removeDuplicates(s);
// }

string removeDuplicates(string S) {
    stack<char> st;
    for (char c : S) {
        if (st.empty() || st.top() != c) {
            st.push(c);
        } else {
            st.pop();
        }
    }
    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// string removeDuplicates(string S) {
//     string res;
//     for (char c : S) {
//         if (!res.empty() && c == res.back()) {
//             res.pop_back();
//         } else {
//             res.push_back(c);
//         }
//     }
//     return res;
// }

string removeDuplicates(string S) {
    string res;
    for (char c : S) {
        if (res.empty() || c != res.back()) {
            res.push_back(c);
        } else {
            res.pop_back();
        }
    }
    return res;
}