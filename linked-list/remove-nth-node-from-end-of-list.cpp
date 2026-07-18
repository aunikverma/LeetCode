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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = 0; // size of list
        ListNode* node = head;
        while (node) {
            s++;
            node = node->next;
        } // got the size

        int t = s - n; // target

        if (t == 0) // first element to delete
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < t; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};