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
        int first_critical = -1;
        int prev_critical = -1;
        int min_dist = INT_MAX;
        int curr_critical = -1;

        ListNode* prev = NULL;
        ListNode* curr = head;
        int i = 1;

        while (curr) {
            if (prev && curr->next) {
                int prev_val = prev->val;
                int curr_val = curr->val;
                int next_val = curr->next->val;

                if ((curr_val > prev_val && curr_val > next_val) ||
                    (curr_val < prev_val && curr_val < next_val)) {
                    if (first_critical == -1) {
                        first_critical = i;
                        curr_critical = i;
                        prev_critical = i;
                    } else {
                        prev_critical = curr_critical;
                        curr_critical = i;
                        min_dist =
                            min(min_dist, (curr_critical - prev_critical));
                    }
                }
            }
            i += 1;
            prev = curr;
            curr = curr->next;
        }
        int max_dist = (curr_critical - first_critical);
        if (first_critical == -1 || min_dist == INT_MAX || max_dist == 0) {
            return {-1, -1};
        }

        return {min_dist, max_dist};
    }
};