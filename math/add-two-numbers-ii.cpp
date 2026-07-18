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
    ListNode* reverse_list(ListNode* l1) {
        ListNode* curr = l1;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_list(l1);
        l2 = reverse_list(l2); // reversing the lists same like ques 2
        ListNode* dummy = new ListNode(0); // Create a dummy node
        ListNode* tail = dummy;            // Tail to build the result list
        int carry = 0;                     // Initialize carry as 0

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int d1 = (l1 != NULL) ? l1->val : 0; // Value from l1 or 0
            int d2 = (l2 != NULL) ? l2->val : 0; // Value from l2 or 0

            int sum = d1 + d2 + carry; // Calculate sum with carry
            int val = sum % 10;        // Extract current digit
            carry = sum / 10;          // Update carry

            ListNode* newNode =
                new ListNode(val); // Create a node with value `val`
            tail->next = newNode;  // Append to result list
            tail = tail->next;     // Move the tail pointer

            if (l1 != NULL)
                l1 = l1->next; // Move l1 pointer if not null
            if (l2 != NULL)
                l2 = l2->next; // Move l2 pointer if not null
        }
        ListNode* result = dummy->next; // Get the result list
        delete dummy;         // Delete dummy node to prevent memory leak
        result = reverse_list(result); // reversing ans
        return result;        // Return the result
    }
};