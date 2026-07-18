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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* ptr = head;
        ListNode* ptr1 = head;
        while (ptr) {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        swap(arr[k - 1], arr[arr.size() - k]);
        int c = 0;
        while (ptr1) {
            ptr1->val = arr[c++];
            ptr1 = ptr1->next;
        }
        return head;
    }
};