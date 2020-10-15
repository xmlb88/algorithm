#include <iostream>
#include "listNode.h"
using namespace std;

void deleteNode(ListNode* node) {
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
}