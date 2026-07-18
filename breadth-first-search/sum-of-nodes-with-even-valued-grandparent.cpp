class Solution {
private:
    int dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (!root) return 0;
        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0) sum += root->val;
        sum += dfs(root->left, root, parent); //root will be parent 
        sum += dfs(root->right, root, parent); //parent will be grandparent for next nodes
        return sum;
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
};