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
    bool solve(TreeNode* root, long long  min, long long max) {
        if (root == NULL) return true;
        if (root->val > min && root->val < max) {
            bool left = solve(root->left, min, root->val); //CHECK ON LEFT
            bool right = solve(root->right, root->val, max); //CHECK ON RIGHT
            return (left && right); //IF BOTH CORRECT
        }
        return false;
    }

public:
    bool isValidBST(TreeNode* root) { return solve(root,-2147483650,2147483650); }
};