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
public:
    const int M = 1e9 + 7;
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, long long>& mp) {
        if (root->left == NULL && root->right == NULL) {
            mp[root] = root->val;
            return;
        }
        long long left = 0, right = 0;
        if (root->left) {
            dfs(root->left, mp);
            left = mp[root->left];
        }
        if (root->right) {
            dfs(root->right, mp);
            right = mp[root->right];
        }
        mp[root] = left + right + root->val;
        return;
    }

    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, long long> mp;
        // making subtree sum
        dfs(root, mp);
        int total_sum = mp[root];
        long long ans = 0;
        for (auto& v : mp) {
            long long product = (total_sum - v.second) * v.second;
            ans = max(ans, product);
        }
        return ans % M;
    }
};