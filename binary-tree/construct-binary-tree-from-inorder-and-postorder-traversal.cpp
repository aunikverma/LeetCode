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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postindex, int instart, int inend,
                    unordered_map<int, int>& mp) {
        // base case
        if (postindex < 0 || instart > inend) {
            return NULL; // out of bounds
        }

        int element = postorder[postindex--];

        TreeNode* root = new TreeNode(element);

        int pos = mp[element];

        // recursion
        root->right = solve(inorder, postorder, postindex, pos + 1, inend, mp);

        root->left = solve(inorder, postorder, postindex, instart, pos - 1, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postindex = n - 1; // post index
        // mapping of inorder
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* ans = solve(inorder, postorder, postindex, 0, n - 1, mp);
        return ans;
    }
};