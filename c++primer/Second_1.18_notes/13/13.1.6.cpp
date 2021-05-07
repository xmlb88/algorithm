#include <iostream>
using namespace std;

struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete; // ×èÖ¹¿½±´
    NoCopy &operator=(const NoCopy&) = delete; // ×èÖ¹¸³Öµ
    ~NoCopy() = default;
};

int main() {
    NoCopy n;
    // NoCopy m(n);
    NoCopy m;
    // m = n;
}