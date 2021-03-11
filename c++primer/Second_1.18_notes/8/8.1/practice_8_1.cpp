#include <iostream>
#include <string>
using namespace std;

// istream& read(istream& is) {
//     auto old_state = is.rdstate();
//     string s;
//     is >> s;
//     cout << s << endl;
//     is.setstate(old_state);
//     return is;
// }

istream& func(istream& is) {
    string buf;
    while (is >> buf) {
        cout << buf << endl;
    }
    is.clear();
    return is;
}

int main() {
    func(cin);
    cout << cin.rdstate() << endl;
    cout << cin.good() << endl;
}