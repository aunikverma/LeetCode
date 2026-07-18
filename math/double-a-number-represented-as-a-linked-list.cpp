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
private:
    void reverse_list(ListNode* head) {
        vector<int> ans;
        ListNode* node = head;
        while (node) {
            ans.push_back(node->val);
            node = node->next;
        }
        node = head;
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (node) {
            node->val = ans[i++];
            node = node->next;
        }
    }

public:
    ListNode* doubleIt(ListNode* head) {
        reverse_list(head);
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* node = head;
        int carry = 0;
        while (node || carry > 0) {
            int val = (node ? node->val : 0) * 2 + carry;  // Double the value and add carry
            carry = val / 10; // Update carry
            tail->next = new ListNode(val % 10); // Create a new node with the digit
            tail = tail->next;          // Move the tail
            if (node) node = node->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        reverse_list(result);
        return result;
    }
};