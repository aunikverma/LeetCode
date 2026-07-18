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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* node = head;
        while (node) {
            arr.push_back(node->val);
            node = node->next;
        }
        left -= 1;
        right -= 1;
        while (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        node = head;
        int k = 0;
        while (node) {
            node->val = arr[k++];
            node = node->next;
        }
        return head;
    }
};