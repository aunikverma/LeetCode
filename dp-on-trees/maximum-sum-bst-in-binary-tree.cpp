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
    class info {
    public:
        int maxi;
        int mini;
        bool isBst;
        int size;
        int sum;
    };

    info solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return {INT_MIN, INT_MAX, true, 0, 0};
        }

        info left_tree = solve(root->left, ans);
        info right_tree = solve(root->right, ans);

        info curr;
        curr.size = left_tree.size + right_tree.size + 1;
        curr.mini = min(root->val, left_tree.mini);
        curr.maxi = max(root->val, right_tree.maxi);
        curr.sum = left_tree.sum + right_tree.sum + root->val;

        if (left_tree.isBst && right_tree.isBst &&
            (root->val > left_tree.maxi && root->val < right_tree.mini)) {
            curr.isBst = true;
            ans = max(ans, curr.sum);
        } else {
            curr.isBst = false;
        }
        return curr;
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};