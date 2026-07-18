/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = NULL;
            int n = q.size();
            int a = INT_MIN;
            while(n)
            {
                curr = q.front();
                q.pop();
                a = max(a,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                n--;
            }
            ans.push_back(a);
        }
        return ans;
    }
};