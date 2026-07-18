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
        if (!root)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }

    TreeNode* solve(vector<int>& r, int s, int e) {
        if (s > e)
            return NULL;
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(r[mid]);
        root->left = solve(r, s, mid - 1);
        root->right = solve(r, mid + 1, e);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> r;
        inorder(root, r);
        return solve(r, 0, r.size() - 1);
    }
};