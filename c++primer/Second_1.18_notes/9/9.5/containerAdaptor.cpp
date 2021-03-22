#include <iostream>
#include <stack>
#include <queue>
// #include <priority_queue>
using namespace std;

int main() {
    // 顺序容器适配器
    // stack, queue, priority_queue
    /* 
        所有容器适配器都支持的操作和类型
        size_type
        value_type
        container_type
        A a;
        A a(c);
        关系运算符
        a.empty()
        a.size()
        swap(a, b)
        a.swap(b)
     */

    deque<int> deq;
    stack<int> stk(deq);
    // 默认情况：stack queue基于deque priority_queue基于vector

    // 重载默认容器类型
    stack<string, vector<string>> str_stk;  // 在vector上实现的空栈
    stack<string, vector<string>> str_stk2(svec);   // 在vector上实现，初始化时保存svec的拷贝

    stack<int> intStack; // 空栈
    for (size_t ix = 0; ix != 10; ++ix) 
        intStack.push(ix);
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
    }

    /* 
        未列出的栈操作
        s.pop()
        s.push(item)
        s.emplace(args)
        s.top()
         */

    // 队列适配器
    // queue和priority_queue头文件 #include <queue>
    /* 
        queue和priority_queue的操作
        q.pop()
        q.front()
        q.back()    // 只queue
        q.top()
        q.push(item)
        q.emplace(args)
     */

}