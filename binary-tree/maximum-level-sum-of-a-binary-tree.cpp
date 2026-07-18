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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        queue<TreeNode*> q;
        int ans = 0, max_levelsum = INT_MIN;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int level_sum = 0;
            while (n) {
                TreeNode* curr = q.front();
                q.pop();
                level_sum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                n--;
            }
            if (level_sum > max_levelsum) {
                ans = level;
                max_levelsum = level_sum;
            }
            level++;
        }
        return ans;
    }
};