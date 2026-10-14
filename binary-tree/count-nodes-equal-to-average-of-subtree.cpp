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

    pair<int, int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        if (!root->left && !root->right) {
            ans++;
            return {1, root->val};
        }
        auto [left_count, left_sum] = solve(root->left);
        auto [right_count, right_sum] = solve(root->right);
        int sum = left_sum + right_sum + root->val;
        int count = left_count + right_count + 1;
        int average = (sum / count);
        ans += (average == root->val ? 1 : 0);
        return {count, sum};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};