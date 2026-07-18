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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        // dummy node
        ListNode* dummy = new ListNode(0);
        // tail of dummy node
        ListNode* tail = dummy;

        while (curr) {
            // first zero
            if (curr->val == 0) {
                if (curr->next) {
                    curr = curr->next;
                    int sum = 0;
                    // add sum until last zero
                    while (curr && curr->val != 0) {
                        sum += curr->val;
                        curr = curr->next;
                    }
                    // make new node
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                } else {
                    // last node
                    curr = curr->next;
                }
            } else {
                // not btween zeroes
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }
        }

        ListNode* result = dummy->next;
        dummy->next = NULL;
        delete dummy;

        return result;
    }
};