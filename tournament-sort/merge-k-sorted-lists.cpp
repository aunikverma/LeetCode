class compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return (a->val > b->val); }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int k = lists.size();
        if (k == 0) {
            return NULL; // base case
        }
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            if (head == NULL) {
                head = temp; // new sorted list head
                tail = temp;
            } else {
                tail->next = temp; // insert at end
                tail = tail->next;
            }
            if (tail->next != NULL) {
                pq.push(tail->next); // next node
            }
        }
        return head;
    }
};