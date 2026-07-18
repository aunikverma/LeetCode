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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;//using bfs
        q.push(root);
        while (!q.empty()) {//to get the last element of the each level
            int n = q.size();
            TreeNode* curr = NULL;
            while (n > 0) {
                curr = q.front();//size and at last curr will hold the last level element
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
            ans.push_back(curr->val);
        }
        return ans;
    }
};