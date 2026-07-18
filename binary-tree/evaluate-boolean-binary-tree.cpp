class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root) return true;
        if (root->left == NULL && root->right == NULL) // leaf node
        {
            return (root->val == 0) ? false : true;
        }
        bool left = evaluateTree(root->left); //postorder
        bool right = evaluateTree(root->right);
        return (root->val == 2) ? (left || right) : (left && right); //2 then or : 3 then and
    }
};