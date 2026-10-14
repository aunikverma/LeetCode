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
    int ans = 0;

    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lefty = solve(root->left);
        int righty = solve(root->right);

        int leftPath = 0, rightPath = 0;
        if (root->left && root->val == root->left->val) {
            leftPath = lefty + 1;
        }
        if (root->right && root->val == root->right->val) {
            rightPath = righty + 1;
        }
        // combined
        ans = max(ans, leftPath + rightPath);
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};