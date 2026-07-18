/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void inorder(vector<TreeNode*>& r, TreeNode* root) {
        if (root == NULL) return;
        inorder(r, root->left);
        r.push_back(root);
        inorder(r, root->right);
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,TreeNode* target) {
        vector<TreeNode*> r;
        inorder(r, cloned);
        for (auto i : r) {
            if (i->val == target->val) {
                return i;
            }
        }
        return NULL;
    }
};