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
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            pair<int, int> ans(0, 0);
            return ans;
        }

        pair<int, int> lefty = solve(root->left);
        pair<int, int> righty = solve(root->right);

        pair<int, int> ans;

        ans.first = root->val + lefty.second + righty.second;

        ans.second =
            max(lefty.first, lefty.second) + max(righty.first, righty.second);

        return ans;
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> ans; // same as sumof two non-adjacent nodes in gfg
        ans = solve(root);
        return max(ans.first, ans.second);
    }
};