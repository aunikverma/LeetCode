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
    pair<int, int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> lefty = solve(root->left);
        pair<int, int> righty = solve(root->right);

        pair<int, int> ans;
        // if you rob this house
        ans.first = root->val + lefty.second + righty.second;
        // if you dont rob this
        // we have options to rob its child or not
        ans.second =
            max(lefty.first, lefty.second) + max(righty.first, righty.second);
        return ans;
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};