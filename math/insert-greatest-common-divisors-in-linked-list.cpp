/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
            return head; // base case
        ListNode* node = head;
        while (node && node->next) {
            int a = node->val;
            int b = node->next->val;
            int c = __gcd(a, b);
            ListNode* newnode = new ListNode(c);
            newnode->next = node->next;
            node->next = newnode;
            node = newnode->next;
        }
        return head;
    }
};