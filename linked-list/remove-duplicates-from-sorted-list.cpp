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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while (node && node->next) {
            if (node->val == node->next->val) {//if next node val is equal
                ListNode* temp = node->next;//store next node iin temp
                node->next = node->next->next;//pointing node to next next
                delete temp;//deleting temp
            } else {
                node = node->next;//else node to next/
            }
        }
        return head;
    }
};