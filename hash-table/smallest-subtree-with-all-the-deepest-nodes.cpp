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
private:
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (root == NULL)
            return {0, NULL}; // if root is NULL
        auto left = solve(root->left);
        auto right = solve(root->right); // post order

        if (left.first == right.first) { //if depth equal
            return {left.first + 1, root};
        } else if (left.first > right.first) { //otherwise return deeper subtree
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};