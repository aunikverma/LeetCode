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
    int decimal(string s) {//converting string to decimal
        int ans = 0;
        int h = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            int c = s[i] - '0';
            ans += c * h;
            h *= 2;
        }
        return ans;
    }

public:
    int getDecimalValue(ListNode* head) {
        string a = "";
        ListNode* node = head;
        while (node) {
            a += to_string(node->val);//getting binary no stored in string fromat
            node = node->next;
        }
        return decimal(a);
    }
};