/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;//min moves
    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int curr = l + r + root->val - 1;
        res += abs(curr);
        return curr;
    }
    int distributeCoins(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};