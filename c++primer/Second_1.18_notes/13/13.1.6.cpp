#include <iostream>
using namespace std;

struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete; // ��ֹ����
    NoCopy &operator=(const NoCopy&) = delete; // ��ֹ��ֵ
    ~NoCopy() = default;
};

int main() {
    NoCopy n;
    // NoCopy m(n);
    NoCopy m;
    // m = n;
}