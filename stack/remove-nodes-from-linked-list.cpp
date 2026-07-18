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
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        vector<int> ans;
        ListNode* node = head;
        while (node) {
            arr.push_back(node->val);
            node = node->next;
        }
        int i = arr.size() - 1;
        int c = INT_MIN;
        while (i >= 0) {
            if (i == arr.size() - 1) {
                ans.push_back(arr[i]);
                c = arr[i];
            } else if (arr[i] >= c) {
                ans.push_back(arr[i]);
                c = arr[i];
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int i : ans) {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};