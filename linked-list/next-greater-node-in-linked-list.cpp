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
    void get(ListNode* head, vector<int>& arr) {
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        get(head, arr);
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && curr >= s.top()) {
                s.pop();
            }
            ans[i] = (s.top() == -1) ? 0 : s.top();
            s.push(curr);
        }
        return ans;
    }
};