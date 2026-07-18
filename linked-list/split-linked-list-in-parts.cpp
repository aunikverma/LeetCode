class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        vector<ListNode*> ans; //ans vector
        int n = len / k; // minimum nodes per part
        int r = len % k; // extra nodes to distribute

        temp = head;
        for (int i = 0; i < k; i++) {
            ListNode* part = temp; // start of this part
            int partSize = n + (i < r ? 1 : 0); // extra node for first 'r' parts

            // Move temp forward partSize-1 steps
            for (int j = 0; j < partSize - 1 && temp; j++) {
                temp = temp->next;
            }

            // Cut the list if needed
            if (temp) {
                ListNode* nextPart = temp->next;
                temp->next = nullptr;
                temp = nextPart;
            }

            ans.push_back(part);
        }
        return ans;
    }
};