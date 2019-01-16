#include <iostream>
#include <list>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head;

        int val1 = 0, val2 = 0, carry = 0, digit = 0;
        while(l1 || l2 || carry) {
            val1 = l1?l1->val:0;
            val2 = l2?l2->val:0;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
            carry = (val1 + val2 + carry) / 10;
            digit = (val1 + val2 + carry) % 10;

            p->next = (new ListNode(digit));
            p = p->next;
        }
        return head->next;
    }
};
