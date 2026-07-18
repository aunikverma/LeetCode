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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;//curr to head
        while(curr && curr->next)
        {
            swap(curr->val,curr->next->val);//swapping 1st node with 2nd node value
            curr = curr->next->next;//pointing it to the third node
        }
        return head;//return head
    }
};