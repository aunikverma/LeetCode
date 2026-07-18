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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL || head->next == NULL) {
            return head;//base case
        }
        vector<int> arr;
        ListNode* node = head;
        while (node) {
            arr.push_back(node->val);
            node = node->next;//copying list to vector
        }
        k = k % arr.size();
        while (k) {
            reverse(arr.begin(), arr.end());//rotating vector
            // reverse(arr.begin(), arr.begin() + 1);
            reverse(arr.begin() + 1, arr.end());
            k--;
        }
        node = head;
        int i = 0;//again copying arr to list
        while (node) {
            node->val = arr[i++];
            node = node->next;
        }
        return head;
    }
};