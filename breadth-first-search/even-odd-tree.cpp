/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            TreeNode* curr = NULL;
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;
            while (n) {
                curr = q.front();
                q.pop();
                int val = curr->val;
                if (level % 2 == 0 &&
                    (curr->val % 2 == 0 || curr->val <= prev_val)) {
                    return false;
                }
                if (level % 2 == 1 &&
                    (curr->val % 2 == 1 || curr->val >= prev_val)) {
                    return false;
                }
                prev_val = val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                n--;
            }
            level++;
        }
        return true;
    }
};