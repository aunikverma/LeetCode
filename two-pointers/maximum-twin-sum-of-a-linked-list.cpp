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
    ListNode* find_mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // since size is even
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_node = NULL;
        while (curr) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        // find middle of linked list
        ListNode* mid = find_mid(head);
        // reverse the second half
        mid = reverse(mid);

        ListNode* p1 = head;
        ListNode* p2 = mid;

        int ans = INT_MIN;
        while (p2) {
            ans = max(ans, (p1->val + p2->val));
            p1 = p1->next;
            p2 = p2->next;
        }
        return ans;
    }
};