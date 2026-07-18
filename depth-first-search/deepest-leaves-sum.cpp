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
private:
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    void solve(TreeNode* root, int& ans, int& maxdepth, int depth) {
        if (!root) {
            return;
        }
        if (depth == maxdepth) {
            ans += root->val;
            return;
        }
        solve(root->left, ans, maxdepth, 1 + depth);
        solve(root->right, ans, maxdepth, 1 + depth);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int maxdepth = depth(root); // max depth
        int ans = 0;
        solve(root, ans, maxdepth, 1); // sum of maxdepth nodes
        return ans;
    }
};