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
    void inorder(vector<int>& r, TreeNode* root) { //inorder of bst is sorted 
        if (root == NULL) return;
        inorder(r, root->left);
        r.push_back(root->val);
        inorder(r, root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        vector<int> r;
        inorder(r, root);
        int ans = INT_MAX;
        for (int i = 1; i < r.size(); i++) {
            int a = r[i] - r[i - 1];
            ans = min(ans, a);
        }
        return ans;
    }
};