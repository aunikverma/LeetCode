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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0,head);//val 0 and ptr head
        ListNode* prev = dummy;// head in dummy's next
        ListNode* curr = head;
        while(curr)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                while(curr->next && curr->val == curr->next->val)
                {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;//preev will point at the last good node we want in the ans
        }
        return dummy->next;
    }
};