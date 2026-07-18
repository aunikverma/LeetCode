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
        if (root == NULL) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> a;
        inorder(root, a);//inorder traversal of binary tree is sorted 
        int mini = INT_MAX;
        for (int i = 0; i < a.size() - 1; i++) {//taking minimum diff
            mini = min(mini, abs(a[i] - a[i + 1]));
        }
        return mini;
    }
};