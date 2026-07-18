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
    void inorder(TreeNode* root, vector<int>& r) {
        if(root == NULL) return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> r;
        inorder(root, r);
        TreeNode* newTree = new TreeNode(r[0]);
        TreeNode* temp = newTree;
        for (int i = 1; i < r.size(); i++) {
            temp->right = new TreeNode(r[i]);
            temp = temp->right;
        }
        temp->right = NULL;
        return newTree;
    }
};