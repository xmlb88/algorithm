// priority_queue 堆
#include <iostream>
#include <vector>
#include <queue> // priority_queue 包含在queue中
using namespace std;

// 模板声明带3个参数：
// priority_queue<Type, Container, Functional>
// Type：数据类型 Container：保存数据的容器 Functional：元素比较方式
// Container必须是用数组实现的容器，vector、deque等，但不能用list，默认vector
// 比较方式默认用operator < ，如果后2个参数缺省，优先队列就是大顶堆（降序），队头元素最大

// 返回降序输出
void origin() {
    priority_queue<int> q;
    for (int i = 0; i < 10; i++) q.push(i);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

// pair比较，先按照pair的first元素降序，first相等时，再按照second降序
void compare_pair() {
    priority_queue<pair<int, int>> coll;
    pair<int, int> a(3, 4); pair<int, int> b(3, 5); pair<int, int> c(4, 3);
    coll.push(a); coll.push(b); coll.push(c);
    while (!coll.empty()) {
        cout << coll.top().first << "\t" << coll.top().second << endl;
        coll.pop();
    }
}

// 小顶堆，升序输出
void great() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < 10; i++) q.push(10 - i);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

// pair 小顶堆
void pair_great() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coll;
    pair<int, int> a(3, 4); pair<int, int> b(3, 5); pair<int, int> c(4, 3);
    coll.push(a); coll.push(b); coll.push(c);
    while (!coll.empty()) {
        cout << coll.top().first << "\t" << coll.top().second << endl;
        coll.pop();
    }
}

// 自定义类型，重载operator < 或者重写仿函数
// 重载operator < 的例子：返回true时，说明左边形参的优先级低于右边形参
struct Node {
    int x, y;
    Node(int a = 0, int b = 0):x(a), y(b) {}
};

// 使用 greater 则重载 >
// bool operator < (Node a, Node b) {
//     // 返回true时，a的优先级低于b
//     // x值较大的Node优先级低
//     // x相等时，y大的优先级低
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

// 重写仿函数的例子
// 小顶堆，先按x升序，x相等时，再按y升序
struct cmp{
    bool operator()(Node a, Node b) {
        // 默认less函数
        // 返回true时， a的优先级低于b的优先级（a排b的后面）
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