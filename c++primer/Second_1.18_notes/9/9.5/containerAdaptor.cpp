#include <iostream>
#include <stack>
#include <queue>
// #include <priority_queue>
using namespace std;

int main() {
    // ˳������������
    // stack, queue, priority_queue
    /* 
        ����������������֧�ֵĲ���������
        size_type
        value_type
        container_type
        A a;
        A a(c);
        ��ϵ�����
        a.empty()
        a.size()
        swap(a, b)
        a.swap(b)
     */

    deque<int> deq;
    stack<int> stk(deq);
    // Ĭ�������stack queue����deque priority_queue����vector

    // ����Ĭ����������
    stack<string, vector<string>> str_stk;  // ��vector��ʵ�ֵĿ�ջ
    stack<string, vector<string>> str_stk2(svec);   // ��vector��ʵ�֣���ʼ��ʱ����svec�Ŀ���

    stack<int> intStack; // ��ջ
    for (size_t ix = 0; ix != 10; ++ix) 
        intStack.push(ix);
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
    }

    /* 
        δ�г���ջ����
        s.pop()
        s.push(item)
        s.emplace(args)
        s.top()
         */

    // ����������
    // queue��priority_queueͷ�ļ� #include <queue>
    /* 
        queue��priority_queue�Ĳ���
        q.pop()
        q.front()
        q.back()    // ֻqueue
        q.top()
        q.push(item)
        q.emplace(args)
     */

}