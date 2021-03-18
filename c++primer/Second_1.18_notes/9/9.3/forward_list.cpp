#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    // É¾³ıforward_listÆæÊı
    forward_list<int> flst{1, 1, 2, 3, 3, 5, 6, 7, 8, 9};
    // auto it = flst.begin();
    // while (it != flst.end()) {
    //     if (*it % 2 == 0) {
    //         it = flst.erase_after(it);
    //     }
    // }
    
    

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }

    for (auto it = flst.begin(); it != flst.end(); it++) {
        cout << *it << " ";
    }
}