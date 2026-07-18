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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = NULL;
            int n = q.size();
            vector<TreeNode*> r;
            while (n) {
                curr = q.front();
                q.pop();
                r.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                n--;
            }
            if (level % 2 == 1) {
                int n = r.size() - 1;
                for (int i = 0; i <= n / 2; i++) {
                    int temp = r[i]->val;
                    r[i]->val = r[n - i]->val;
                    r[n - i]->val = temp;
                }
            }
            level++;
        }
        return root;
    }
};