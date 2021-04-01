#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int clumsy(int N) {
    stack<int> st;
    int mul = 1;
    while (N > 0) {
        if (N == 1) {
            st.push(mul * N);
            break;
        } else if (N == 2) {
            st.push(mul * N);
            break;
        } else {
            int a = N, b = --N, c = --N;
            st.push(mul * (a * b / c));
            st.push(--N);
            mul = -1;
            --N;
        }
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

// ջ
int clumsy(int N) {
    stack<int> st;
    st.push(N--);
    int index = 0;
    while (N > 0) {
        if (index % 4 == 0) {
            st.top() *= N;
        } else if (index % 4 == 1) {
            st.top() /= N;
        } else if (index % 4 == 2) {
            st.push(N);
        } else if (index % 4 == 3) {
            st.push(-N);
        }
        ++index;
        --N;
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

// O(1)
/* 
1 1
2 2 * 1 = 2
3 3 * 2 / 1 = 6
4 4 * 3 / 2 + 1 = 7

5 5 * 4 / 3 + 2 - 1 = 7
6 6 * 5 / 4 + 3 - 2 * 1 = 8
7 7 * 6 / 5 + 4 - 3 * 2 / 1 = 6
8 8 * 7 / 6 + 5 - 4 * 3 / 2 + 1 = 9
 */
int clumsy(int N) {
    if (N == 1) return 1;
    else if (N == 2) return 2;
    else if (N == 3) return 6;
    else if (N == 4) return 7;

    if (N % 4 == 0) return N + 1;
    else if (N % 4 <= 2) return N + 2;
    else return N - 1;
}