class FindElements {
public:
    unordered_set<int> search; //to find value
    void recover(TreeNode* root) { //recover tree
        if (!root) {
            return;
        }
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            search.insert(2 * root->val + 1);
            recover(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            search.insert(2 * root->val + 2);
            recover(root->right);
        }
    }
    FindElements(TreeNode* root) {
        if (root) { //if root not null
            root->val = 0;
            search.insert(0);
            recover(root);
        }
    }

    bool find(int target) { return (search.count(target) > 0); }
};
