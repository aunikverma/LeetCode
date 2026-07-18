/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = (!a) ? headB : a = a->next; // when a ends point it to the head of b
            b = (!b) ? headA : b = b->next; // when b ends point it to the head of a
        }
        return b;
    }
};