#include <iostream>
#include <bitset>
using namespace std;

int convertInteger(int A, int B) {
    unsigned c = A ^ B;
    int count = 0;
    while (c) {
        count++;
        c &= (c - 1);
    }
    return count;
}

int convertInteger(int A, int B) {
    return bitset<32>(A ^ B).count(); 
}