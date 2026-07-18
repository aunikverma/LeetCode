class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* n1, TreeNode* n2) {//same like sametree 
        if (n1 == NULL && n2 == NULL) {
            return true;
        }
        if (n1 == NULL || n2 == NULL) {
            return false;
        }
        return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
};