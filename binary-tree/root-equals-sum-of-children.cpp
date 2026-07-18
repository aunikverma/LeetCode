class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        else return(root->val == root->left->val + root->right->val);
    }
};