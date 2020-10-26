#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// definition for a node
class Node{
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

// 方法1
Node* copyRandomList(Node* head) {
    if (!head) return NULL;
    //TODO #5:
    unordered_map<Node*, int> index;
    unordered_map<int, Node*> newindex;
    Node* newHead = new Node(head -> val);
    Node* oldcur = head;
    Node* newcur = newHead;
    int idx = 0;
    while (oldcur) {
        newindex[idx] = newcur;
        index[oldcur] = idx;
        idx++;
        if (oldcur -> next == NULL) {
            newcur -> next = NULL;
        } else {
            newcur -> next = new Node(oldcur -> next -> val);
        }
        newcur = newcur -> next;
        oldcur = oldcur -> next;
    }

    oldcur = head, newcur = newHead;
    while (oldcur) {
        if (oldcur -> random == NULL) {
            newcur -> random = NULL;
        } else {
            int id = index[oldcur -> random];
            newcur -> random = newindex[id];
        }
        oldcur = oldcur -> next;
        newcur = newcur -> next;
    }
    return newHead;
}


// 方法2
Node* copyRandomList(Node* head) {
    if (!head) return NULL;
    copyNodes(head);
    copyRandom(head);
    return getCopy(head);
}

void copyNodes(Node* head) {
    while (head) {
        Node* newNode = new Node(head -> val);
        Node* nextNode = head -> next;
        head -> next = newNode;
        newNode -> next = nextNode;
        head = newNode -> next;
    }
}

void copyRandom(Node* head) {
    while (head) {
        Node* copyNode = head -> next;
        if (head -> random == NULL) {
            copyNode -> random = NULL;
        } else {
            copyNode -> random = head -> random -> next;
        }
        head = head -> next -> next;
    }
}

Node* getCopy(Node* head) {
    Node* pos = head;
    Node* copy = pos -> next;
    Node* newHead = copy;
    while (pos) {
        pos -> next = copy -> next;
        pos = pos -> next;
        if (pos) copy -> next = pos -> next;
        copy = copy -> next;
    }
    return newHead;
}

// 方法1优化
Node* copyRandomList(Node* head) {
    if (!head) return NULL;
    unordered_map<Node*, Node*> match;
    Node* cur = head;
    Node* newHead = new Node(head -> val);
    Node* newcur = newHead;
    match[cur] = newcur;
    while (cur) {
        cur = cur -> next;
        if (!cur) {
            newcur -> next = NULL;
        } else {
            newcur -> next = new Node(cur -> val);
        }
        newcur = newcur -> next;
        match[cur] = newcur;
    }

    cur = head, newcur = newHead;
    while (cur) {
        newcur -> random = match[cur -> random];
        cur = cur -> next;
        newcur = newcur -> next;
    }
    return newHead;
}