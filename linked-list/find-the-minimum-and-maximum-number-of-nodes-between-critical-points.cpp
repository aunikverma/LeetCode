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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // first, prev,curr critical points
        int f = -1, p = -1, c = -1;
        int min_dist = INT_MAX;

        ListNode* prev = NULL;
        ListNode* curr = head;
        int i = 1;

        while (curr) {
            if (prev && curr->next) {
                int p_val = prev->val;
                int c_val = curr->val;
                int n_val = curr->next->val;

                if ((c_val > p_val && c_val > n_val) ||
                    (c_val < p_val && c_val < n_val)) {
                    if (f == -1) {
                        f = p = c = i;
                    } else {
                        p = c;
                        c = i;
                        min_dist = min(min_dist, (c - p));
                    }
                }
            }
            i += 1;
            prev = curr;
            curr = curr->next;
        }
        int max_dist = (c - f);
        if (f == -1 || min_dist == INT_MAX || max_dist == 0) {
            return {-1, -1};
        }
        return {min_dist, max_dist};
    }
};