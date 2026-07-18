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
    void inorder(set<int>&s,TreeNode* root)
    {
        if(root == NULL) return;
        inorder(s,root->left);
        s.insert(root->val);
        inorder(s,root->right);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        set<int>s;
        inorder(s,root);
        return (s.size() == 1);
    }
};