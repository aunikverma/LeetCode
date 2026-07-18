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
    ListNode* removeElements(ListNode* head, int v) {
        while (head && head->val == v) {
            ListNode* temp = head;
            head = head->next; // Move to the next node
            delete temp;     
        }
        
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->next->val == v) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next; // Skip the node with value v
                delete temp; // Free memory
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        return head; // Return updated head
    }
};
