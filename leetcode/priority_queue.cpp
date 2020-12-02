// priority_queue ��
#include <iostream>
#include <vector>
#include <queue> // priority_queue ������queue��
using namespace std;

// ģ��������3��������
// priority_queue<Type, Container, Functional>
// Type���������� Container���������ݵ����� Functional��Ԫ�رȽϷ�ʽ
// Container������������ʵ�ֵ�������vector��deque�ȣ���������list��Ĭ��vector
// �ȽϷ�ʽĬ����operator < �������2������ȱʡ�����ȶ��о��Ǵ󶥶ѣ����򣩣���ͷԪ�����

// ���ؽ������
void origin() {
    priority_queue<int> q;
    for (int i = 0; i < 10; i++) q.push(i);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

// pair�Ƚϣ��Ȱ���pair��firstԪ�ؽ���first���ʱ���ٰ���second����
void compare_pair() {
    priority_queue<pair<int, int>> coll;
    pair<int, int> a(3, 4); pair<int, int> b(3, 5); pair<int, int> c(4, 3);
    coll.push(a); coll.push(b); coll.push(c);
    while (!coll.empty()) {
        cout << coll.top().first << "\t" << coll.top().second << endl;
        coll.pop();
    }
}

// С���ѣ��������
void great() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < 10; i++) q.push(10 - i);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

// pair С����
void pair_great() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coll;
    pair<int, int> a(3, 4); pair<int, int> b(3, 5); pair<int, int> c(4, 3);
    coll.push(a); coll.push(b); coll.push(c);
    while (!coll.empty()) {
        cout << coll.top().first << "\t" << coll.top().second << endl;
        coll.pop();
    }
}

// �Զ������ͣ�����operator < ������д�º���
// ����operator < �����ӣ�����trueʱ��˵������βε����ȼ������ұ��β�
struct Node {
    int x, y;
    Node(int a = 0, int b = 0):x(a), y(b) {}
};

// ʹ�� greater ������ >
// bool operator < (Node a, Node b) {
//     // ����trueʱ��a�����ȼ�����b
//     // xֵ�ϴ��Node���ȼ���
//     // x���ʱ��y������ȼ���
//     if (a.x == b.x) return a.y > b.y;
//     return a.x > b.x;
// }

// void chongZai() {
//     priority_queue<Node> q;
//     for (int i = 0; i < 10; i++)
//         q.push(Node(rand(), rand()));
//     while (!q.empty()) {
//         cout << q.top().x << "\t" << q.top().y << endl;
//         q.pop();
//     }
// }

// ��д�º���������
// С���ѣ��Ȱ�x����x���ʱ���ٰ�y����
struct cmp{
    bool operator()(Node a, Node b) {
        // Ĭ��less����
        // ����trueʱ�� a�����ȼ�����b�����ȼ���a��b�ĺ��棩
        if (a.x == b.x) return a.y > b.y;
        return a.x > b.x;
    }
};

void fang_func() {
    priority_queue<Node, vector<Node>, cmp> q;
    for (int i = 0; i < 10; i++)
        q.push(Node(rand(), rand()));
    while (!q.empty()) {
        cout << q.top().x << "\t" << q.top().y << endl;
        q.pop();
    }
}

int main() {
    // origin();
    // compare_pair();
    // great();
    // pair_great();
    // chongZai();
    fang_func();
    return 0;
}