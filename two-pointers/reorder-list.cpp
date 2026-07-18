class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        if (v.size() % 2 == 1) {
            int m = v.size() / 2;
            ListNode* temp = head;
            for (int i = 0; i < v.size() / 2; i++) {
                temp->val = v[i];
                temp = temp->next;
                temp->val = v[v.size() - 1 - i];
                temp = temp->next;
            }
            temp->val = v[m];
        } else {
            ListNode* temp = head;
            for (int i = 0; i < v.size() / 2; i++) {
                temp->val = v[i];
                temp = temp->next;
                temp->val = v[v.size() - 1 - i];
                temp = temp->next;
            }
        }
    }
};