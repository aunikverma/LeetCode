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
    bool check(string s) {
        int st = 0, e = s.length() - 1;
        while (st < e) {
            if (s[st] != s[e]) {
                return false;
            }
            st++;
            e--;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        string a = "";
        ListNode* node = head;
        while (node) {
            a += to_string(node->val);
            node = node->next;
        }
        cout << a;
        return check(a);
    }
};