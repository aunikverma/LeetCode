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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> s;
        for (int i : nums) {
            s[i]++;
        }
        ListNode* curr = head; // current pointing to head
        while (curr) {
            if (s.find(curr->val) != s.end()) {
                curr = curr->next;
            } else {
                break; // now curr is having the first node which is not in nums
            }
        }
        ListNode* newhead = curr;
        while (curr && curr->next) {
            if (s.find(curr->next->val) != s.end()) {
                curr->next = curr->next->next; // if curr next is in nums then//
                                               // point it to curr next next
            } else {
                curr = curr->next;
            }
        }
        return newhead;
    }
};