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
    void inorder(TreeNode* root, vector<int>& a) {
        if (!root)
            return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
    void putValues(TreeNode* root, vector<int>& a, int& i) {
        if (!root || i > a.size())
            return;
        putValues(root->left, a, i);
        root->val = a[i++];
        putValues(root->right, a, i);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> a;
        inorder(root, a);
        sort(a.begin(), a.end());
        int i = 0;
        putValues(root, a, i);
    }
};