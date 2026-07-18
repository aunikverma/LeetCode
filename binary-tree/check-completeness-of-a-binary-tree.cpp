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
    int countNodes(TreeNode* root)
    {
        if(root == NULL) return 0;
        return (1 + countNodes(root->left) + countNodes(root->right));
    }

    bool is_cbt(TreeNode* root,int i,int total)
    {
        if(root == NULL) return true;
        if(i >= total) return false;
        bool left = is_cbt(root->left,2*i+1,total);
        bool right = is_cbt(root->right,2*i+2,total);
        return (left && right);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int i = 0;//index
        int total = countNodes(root);
        return is_cbt(root,i,total);
    }
};