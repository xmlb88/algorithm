#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// TODO #2:

// 1. 将字符串绑定到输入流istirngstream，使用getline的第三个参数，进行分割
void split(const string& s, vector<int>& sv, const char flag = ' ') {
    sv.clear();
    isstringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
    return;
}

// 2. 使用strtok
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

// review
// 1. 
vector<string> split(string& s, const char flag = ',') {
    istringstream iss(s);
    string str;
    vector<string> result;
    while (getline(iss, str, flag)) {
        result.push_back(str);
    }
    return result;
}

// 2. 
vector<string> split(string& s) {
    vector<string> result;
    char* token = strtok(s.data(), ",");
    while (token != NULL) {
        result.push_back(token);
        token = strtok(NULL, ",");
    }
    return result;
}

// 3. 
vector<string> split(string& s, const string& delemiters = ",") {
    string::size_type lastpos = s.find_first_not_of(delemiters, 0);
    string::size_type pos = s.find_first_of(delemiters, lastpos);
    vector<string> result;
    while (lastpos != string::npos || pos != string::npos) {
        result.push_back(s.substr(lastpos, pos - lastpos));
        lastpos = s.find_first_not_of(delemiters, pos);
        pos = s.find_first_of(delemiters, lastpos);
    }
}

// review 
vector<string> split(string& s, const string& delemiters = ',') {
    string::size_type lastpos = s.find_first_not_of(delemiters, 0);
    string::size_type pos = s.find_first_of(delemiters, lastpos);
    vector<string> result;
    while (lastpos != string::npos || pos != string::npos) {
        result.push_back(s.substr(lastpos, pos - lastpos));
        lastpos = s.find_first_not_of(delemiters, pos);
        pos = s.find_first_of(delemiters, lastpos);
    }
}