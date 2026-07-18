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
    void inorder(TreeNode* root, vector<int>& r, vector<TreeNode*>& nodes) {
        if (root == NULL)
            return;
        inorder(root->left, r, nodes);
        r.push_back(root->val);
        nodes.push_back(root);
        inorder(root->right, r, nodes);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return root;
        vector<int> r;
        vector<TreeNode*> nodes;
        inorder(root, r, nodes);
        int c = r[r.size() - 1];
        for (int i = r.size() - 2; i >= 0; i--) {
            c += r[i]; //finding correct sum using suffix sum inorder
            r[i] = c;
        }
        for (int i = 0; i < r.size(); i++) {
            auto node = nodes[i]; //storing values in tree using inorder root 
            node->val = r[i];
        }
        return root;
    }
};