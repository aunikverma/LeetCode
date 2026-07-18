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
    void inorder(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == NULL)
            return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return {root->val};
        unordered_map<int, int> mp;
        inorder(root, mp);
        vector<int> ans;
        int maxi = INT_MIN;
        for (auto& v : mp) {
            maxi = max(maxi, v.second);
        }
        for (auto& v : mp) {
            if (v.second == maxi) {
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};