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
    void inorder(unordered_map<int, int>& mp, TreeNode* root) {
        if (root == NULL) return;
        inorder(mp, root->left);
        mp[root->val]++;
        inorder(mp, root->right);
    }

    bool present(unordered_map<int, int> mp, int k) {
        for (auto& v : mp) {
            int a = k - v.first;
            if (mp.find(a) != mp.end() && a != v.first) {
                return true;
            }
        }
        return false;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        unordered_map<int, int> mp;
        inorder(mp, root); // nodes val in vector r
        return present(mp, k);
    }
};