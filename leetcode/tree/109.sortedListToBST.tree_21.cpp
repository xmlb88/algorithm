#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* mid = slow -> next;
    slow -> next = NULL;

    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur) {
        ListNode node* = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    return helper(pre, mid);

}

TreeNode* helper(ListNode* le, ListNode* ri) {
    TreeNode* root = new TreeNode(le -> val);
    le = le -> next;

    TreeNode* left = root;
    TreeNode* right = root;

    while (le && ri) {
        TreeNode* node_left = new TreeNode(le -> val);
        TreeNode* node_right = new TreeNode(ri -> val);
        left -> left = node_left;
        right -> right = node_right;
        left = left -> left;
        right = right -> right;
        le = le -> next;
        ri = ri -> next;
    }

    if (ri) {
        right -> right = new TreeNode(ri -> val);
    }

    if (le) {
        left -> left = new TreeNode(le -> val);
    }

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    if (!head -> next) return new TreeNode(head -> val);

    // ����ָ���ҵ��е�
    ListNode *pre = head, *slow = head -> next, *fast = head -> next -> next;
    while (fast && fast -> next) {
        pre = pre -> next;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    pre -> next = NULL;
    TreeNode* root = new TreeNode(slow -> val);
    root -> left = sortedListToBST(head);
    root -> right = sortedListToBST(slow -> next);
    return root;
}


// review 2021��5��18��09:13:52
// 1 4 2 3 
// ����ָ���������е㣬�жϺ�ֱ𹹽���
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head -> next) return new TreeNode(head -> val);

    // �ÿ���ָ���ҵ�������е���Ϊ���ڵ�
    // ������Ϊ����ʱ���������ģ�ż��������
    // ����slowǰ���ڵ㷽����е��ж�
    ListNode *slow = head, *fast = head, *pre;
    while (fast && fast -> next) {
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    pre -> next = nullptr;
    // head -> ... pre -> nullptr; slow -> ... -> fast -> nullptr;
    TreeNode* root = new TreeNode(slow -> val);
    root -> left = sortedListToBST(head);
    root -> right = sortedListToBST(slow -> next);
    return root;
}
// ʱ��O(nlogn)
// �ռ�O(logn)

// ����ת��Ϊ�����ٷ���
vector<int> vec;
TreeNode* makeTree(int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(vec[mid]);
    root -> left = makeTree(start, mid - 1);
    root -> right = makeTree(mid + 1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    while (head) {
        vec.push_back(head -> val);
        head = head -> next;
    }
    return makeTree(0, vec.size() - 1);
}
// ʱ��O(n)
// �ռ�O(n)

// �Ż���ֱ�ӽ����������
ListNode* newHead;
int getListLength(ListNode* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head -> next;
    }
    return length;
}

TreeNode* makeTree(int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode();    // �ݲ���ֵ
    // �ȹ���������
    root -> left = makeTree(start, mid - 1);
    // ��ֵ��headǰ��
    root -> val = newHead -> val;
    newHead = newHead -> next;
    root -> right = makeTree(mid + 1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    newHead = head;
    int length = getListLength(head);
    return makeTree(0, length - 1);
}

// �Ż���ֱ�ӽ����������
int getListLength(ListNode* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head -> next;
    }
    return length;
}

// head����������&���������ⲿ����
TreeNode* makeTree(ListNode*& head, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode();    // ��ռ�ӣ��ݲ���ֵ
    root -> left = makeTree(head, start, mid - 1);
    // ����ʱ����ֵ��head����
    root -> val = head -> val;
    head = head -> next;
    root -> right = makeTree(head, mid + 1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int length = getListLength(head);
    return makeTree(head, 0, length - 1);
}
// ʱ��O(n)
// �ռ�O(logn)