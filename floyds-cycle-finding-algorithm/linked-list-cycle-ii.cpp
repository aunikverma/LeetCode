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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head; // shraddha mam solution
        while (fast && fast->next) {
            slow = slow->next;       // move slow one
            fast = fast->next->next; // move fast twice
            if (slow == fast) {      // when become equal break
                break;
            }
        }
        if (!fast || !fast->next) return NULL; // base case 2
        slow = head;     // again initialize slow to head
        while (slow != fast) {
            slow = slow->next; // now increment both pointer one until they matches
            fast = fast->next;
        }
        return slow;
    }
};