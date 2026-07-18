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
    ListNode* gettail(ListNode* node) {
        ListNode* curr = node;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        return curr;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* taillist2 = gettail(list2); // tail of list2
        ListNode* curr = list1;
        int pos = 1;
        while (pos < a) {
            curr = curr->next;
            pos++;
        }
        ListNode* temp = curr;
        while (pos <= b) {
            temp = temp->next;
            pos++;
        }
        curr->next = list2;
        taillist2->next = temp->next;
        return list1;
    }
};