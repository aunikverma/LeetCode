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
    vector<vector<int>> spiralMatrix(int row, int col, ListNode* head) {
        vector<vector<int>> mat(row, vector<int>(col, -1));
        int strow = 0;       // starting row
        int stcol = 0;       // starting col
        int enrow = row - 1; // end row
        int encol = col - 1; // end col
        ListNode* node = head;
        while (node && strow <= enrow && stcol <= encol) {
            // first row
            for (int i = stcol; i <= encol && node; i++) {
                mat[strow][i] = node->val;
                node = node->next;
            }
            strow++;
            // last col
            for (int i = strow; i <= enrow && node; i++) {
                mat[i][encol] = node->val;
                node = node->next;
            }
            encol--;
            // last row
            for (int i = encol; i >= stcol && node; i--) {
                mat[enrow][i] = node->val;
                node = node->next;
            }
            enrow--;
            // first col
            for (int i = enrow; i >= strow && node; i--) {
                mat[i][stcol] = node->val;
                node = node->next;
            }
            stcol++;
        }
        return mat;
    }
};