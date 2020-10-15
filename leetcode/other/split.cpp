#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// TODO #2:

// 1. ���ַ����󶨵�������istirngstream��ʹ��getline�ĵ��������������зָ�
void split(const string& s, vector<int>& sv, const char flag = ' ') {
    sv.clear();
    isstringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
    return;
}

// 2. ʹ��strtok
int main() {
    string str = "one two three four five";
    char *token = strtok(str.data(), " ")
    while (token != NULL) {
        cout << token << '\n';
        token = strtok(NULL, " ");
    }
}

// 3. 
void split(const string& s, vector<string>& tokens, const string& delemiters = " ") {
    string::size_type lastpos = s.find_first_not_of(delemiters, 0);
    string::size_type pos = s.find_first_of(delemiters, lastpos);
    while (string::npos != pos || string::npos != lastpos) {
        tokens.push_back(s.substr(lastpos, pos - lastpos));
        lastpos = s.find_first_not_of(delemiters, pos);
        pos = s.find_first_of(delemiters, lastpos);
    }
}