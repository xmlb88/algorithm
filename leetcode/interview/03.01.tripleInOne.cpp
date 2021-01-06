#include <iostream>
#include <vector>
using namespace std;


// NOT SOLVED
class TripleInOne {
    vector<int> res;
    unordered_map<int,int> m;
    int Stacksize;
public:
    TripleInOne(int stackSize) {
        Stacksize = stackSize;
        res.resize(3*stackSize+3);
        m[0] = 0, m[1] = stackSize+1, m[2] = 2*stackSize+2;
    }
    
    void push(int stackNum, int value) {
        if(m[stackNum] < (stackNum+1)*(Stacksize+1)-1) res[++m[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if(m[stackNum] > stackNum*(Stacksize+1)) return res[m[stackNum]--];
        return -1;
    }
    
    int peek(int stackNum) {
        if(m[stackNum] > stackNum*(Stacksize+1)) return res[m[stackNum]];
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        return m[stackNum] == stackNum*(Stacksize+1);
    }
};

作者：bueryt
链接：https://leetcode-cn.com/problems/three-in-one-lcci/solution/shu-zu-jian-ji-xie-fa-by-bueryt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。