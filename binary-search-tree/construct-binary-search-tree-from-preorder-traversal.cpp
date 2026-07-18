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
    TreeNode* solve(vector<int>& preOrder, int mini, int maxi, int& i) {
        if (i >= preOrder.size()) return NULL; //base case 1
        if (preOrder[i] < mini || preOrder[i] > maxi) { //base case 2
            return NULL;
        }
        TreeNode* root = new TreeNode(preOrder[i++]);
        root->left = solve(preOrder, mini, root->val, i);
        root->right = solve(preOrder, root->val, maxi, i);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        int i = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return solve(preOrder, mini, maxi, i);
    }
};