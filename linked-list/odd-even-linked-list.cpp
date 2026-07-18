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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> arr;
        vector<int> arr1;
        ListNode* node = head;
        while (node) {
            arr.push_back(node->val);//pushing into vector
            node = node->next;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                arr1.push_back(arr[i]);// changing values in arr1
            }
        }
        for (int i = 1; i < arr.size(); i++) {
            if (i % 2 == 1) {
                arr1.push_back(arr[i]);
            }
        }
        node = head;
        int i = 0;
        while (node) {
            node->val = arr1[i++];//adding values into list
            node = node->next;
        }
        return head;
    }
};