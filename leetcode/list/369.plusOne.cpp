#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* plusOne(ListNode* head) {
    ListNode* sentinel = new ListNode(0);
    sentinel -> next = head;
    ListNode* notNine = sentinel;

    // find the rightmost not-nine digit
    while (head) {
        if (head -> val != 9) notNine = head;
        head = head -> next;
    }

    // increase this rightmost not-nine digit by 1
    notNine -> val++;
    notNine = notNine -> next;

    while (notNine) {
        notNine -> val = 0;
        notNine = notNine -> next;
    }

    return sentinel -> val != 0 ? sentinel : sentinel -> next;
}