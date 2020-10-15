#include <iostream>
#include <string>
using namespace std;

string multiply(string mul1, string mul2) {

}

string sumply(string mul1, string mul2) {
    int i = mul1.length() - 1, j = mul2.length() - 1;
    int mor = 0;
    string res;
    while (i >= 0 && j >= 0) {
        int sum1 = mul1[i] - '0';
        int sum2 = mul2[j] - '0';
        int sum = sum1 + sum2 + mor;
        res += to_string(sum / 10);
        mor = sum % 10;
        i--;
        j--;
    }
    if (i == -1) {
        while (j >= 0) {
            int sum2 = mul2[j] - '0';
            int sum = sum2 + mor;
            res += to_string(sum / 10);
            mor = sum % 10;
            j--;
        }
    }
    if (j == -1) {
        while (i >= 0) {
            int sum1 = mul1[i] - '0';
            int sum = sum1 + mor;
            res += to_string(sum / 10);
            mor = sum % 10;
            i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// TODO:
// FIXME:

string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    // ������Ϊm+nλ��
    vector<int> res(m + n, 0);
    // �Ӹ�λ��ʼ��Ϊ���              
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            // �˻���res��Ӧ������λ��
            int p1 = i + j, p2 = i + j + 1;
            // ���ӵ�res
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    // ���ǰ׺���ܴ��0
    int i = 0;
    while (i < res.size() && res[i] == 0) {
        i++;
    }
    string str;
    for (; i < res.size(); i++) {
        str.push_back('0' + res[i]);
    }

    return str.size() == 0? "0" : str;

}

string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    string result;
    int i = 0;
    while (res[i] == 0 && i < res.size()) i++;
    while (i < res.size()) {
        result.push_back('0' + res[i]);
        i++;
    }
    return result.size() == 0 ? "0" : result;
}