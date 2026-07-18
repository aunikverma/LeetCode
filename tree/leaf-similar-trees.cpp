class Solution {
private:
    void leafs(TreeNode* root, vector<int>& a) {
        if (!root) return;
        if (root->left == NULL && root->right == NULL) {
            a.push_back(root->val);
            return;
        }
        leafs(root->left, a);
        leafs(root->right, a);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        leafs(root1, a);
        leafs(root2, b);
        return (a == b);
    }
};