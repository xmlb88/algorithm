#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO:
void print(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int kthGrammar(int n, int k) {
    string str = "0";
    string temp;
    for (int i = 1; i < n; ++i) {
        for (int c : str) {
            if (c == 0) {
                temp.push_back('0');
                temp.push_back('1');
            } else {
                temp.push_back('1');
                temp.push_back('0');
            }
        }
        str = temp;
        temp.clear();
        if (str.size() >= k) return str[k - 1] - '0';
    }
    return str[k - 1] - '0';
}

// 01
// 0110
// 01101001
// 0110100110010110
// 01101001100101101001011001101001
// 0110100110010110100101100110100110010110011010010110100110010110
// 01101001100101101001011001101001100101100110100101101001100101101001011001101001011010011001011001101001100101101001011001101001
// 0110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110011010011001011010010110011010010110100110010110100101100110100110010110011010010110100110010110


int kthGrammar(int n, int k) {

}

int main() {
    cout << kthGrammar(3, 3) << endl;
}