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
    TreeNode* solve(TreeNode* root, int t) {
        if (root == NULL) {
            return NULL; // base case
        }

        root->left = solve(root->left, t);   // left
        root->right = solve(root->right, t); // right

        if (root->left == NULL && root->right == NULL && root->val == t) {
            return NULL; // if leaf and val == target
        }

        return root; //return as it is
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = solve(root, target);
        return root;
    }
};