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
    bool hasPathSum(TreeNode* root, int targetsum) {
        if (root == NULL) {
            return false;
        }
        //using dfs
        targetsum -= root->val;

        if (root->left == NULL && root->right == NULL) { //check if it is leaf node targetsum equals 0
            return (targetsum == 0);
        }
        return (hasPathSum(root->left, targetsum) || hasPathSum(root->right, targetsum));
    }
};