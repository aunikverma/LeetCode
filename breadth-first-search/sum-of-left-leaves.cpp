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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* curr = NULL;
            while (n) {
                curr = q.front();
                q.pop();
                if (curr->left) { // only left leaf node or left last node
                    if (curr->left->left == NULL && curr->left->right == NULL) {
                        ans += curr->left->val;
                    }
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                n--;
            }
        }
        return ans;
    }
};