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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val); //if root null create
        } else if (root->val < val) {
            TreeNode* r = new TreeNode(val);
            r->left = root; //if val is greater craete node insert in left
            return r;
        } else if (root->val > val) {//if less check in right 
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};