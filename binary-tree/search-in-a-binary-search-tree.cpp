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
private:
    TreeNode* solve(TreeNode* root,int v)
    {
        if(root == NULL) return NULL;
        if(root->val == v) return root;
        else if(root->val > v) return searchBST(root->left,v);
        else return searchBST(root->right,v);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};