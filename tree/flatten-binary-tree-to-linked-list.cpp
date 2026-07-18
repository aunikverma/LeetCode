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
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current != NULL) {
            if (current->left) {
                TreeNode* predecessor = current->left;
                while (predecessor->right != NULL) {
                    predecessor = predecessor->right;
                }
                predecessor->right = current->right;
                current->right = current->left;
                current->left = NULL; //if not want to use next loop
            }
            current = current->right;
        }
        // // left ko NULL
        // current = root;
        // while (current != NULL) {
        //     current->left = NULL;
        //     current = current->right;
        // }
    }
};