#include <iostream>
#include <string>
using namespace std;

int main() {
    string headStr;
    int totalNum = 0;
    if (cin >> headStr) {
        totalNum = 1;
        string nextStr;
        while (cin >> nextStr) {
            if (nextStr == headStr) {
                totalNum++;
            } else {
                cout << headStr << " occurs " << totalNum << " times." << endl;
                headStr = nextStr;
                totalNum = 1;
            }
        }

        cout << headStr << " occurs " << totalNum << " times." << endl;
    } else {
        cerr << "No Data !" << endl;
    }
    return 0;
}