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
    int count(vector<int>& arr, int x) {
        int c = 0;
        for (int i : arr) {
            if (i < x) {
                c++;
            }
        }
        return c++;
    }

public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr;
        ListNode* node = head;
        while (node) {
            arr.push_back(node->val);
            node = node->next;//adding elements of list to array
        }
        vector<int> new1(arr.size());//creating new vector
        int c = count(arr, x);//counted elements less than x
        int k = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < x) {
                new1[k++] = arr[i];//adding elements on the front whose values are smaller than x
            } else {
                new1[c++] = arr[i];//bigger than x from c
            }
        }
        node = head;
        k = 0;
        while (node) {//updating node values from new1
            node->val = new1[k++];
            node = node->next;
        }
        return head;
    }
};