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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>arr;
        ListNode* node = head;
        ListNode* node1 = head;
        while(node)
        {
            arr.push_back(node->val);
            node = node->next;
        }
        sort(arr.begin(),arr.end());
        int k  = 0;
        while(node1)
        {
            node1->val = arr[k++];
            node1 = node1->next;
        }
        return head;
    }
};