#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;

void stringToTime(string lightOn) {
    int hour = 0;
    for (int i = 0; i < 4; ++i) {
        if (lightOn[i] == '1') {
            hour += (1 << i);
        }
    }

    if (hour > 11) return;

    int minute = 0;
    for (int i = 4; i < 10; ++i) {
        if (lightOn[i] == '1') {
            minute += (1 << (i - 4));
        }
    }

    if (minute > 59) return;
    string str_minute;
    if (minute < 10) str_minute = "0" + to_string(minute);
    else str_minute = to_string(minute);
    res.push_back(to_string(hour) + ":" + str_minute);
}

void dfs(string lightOn, int turnedOn, int start) {
    if (turnedOn == 0) {
        stringToTime(lightOn);
        return;
    }

    int n = lightOn.size();
    if (start == n) return;

    for (int i = start; i < n; ++i) {
        lightOn[i] = '1';
        dfs(lightOn, turnedOn - 1, i + 1);
        lightOn[i] = '0';
    }
}

vector<string> readBinaryWatch(int turnedOn) {
    string lightOn(10, '0');
    dfs(lightOn, turnedOn, 0);
    return res;
}

int main() {
    vector<string> res = readBinaryWatch(9);
    for (string& str : res) {
        cout << str << " ";
    }
    cout << endl;
}