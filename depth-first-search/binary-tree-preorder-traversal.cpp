class Solution {
    
  public:
  void morrispreorder(TreeNode* root,vector<int>&ans) {
    TreeNode* current = root;
    
    while (current != NULL) {
        if (current->left == NULL) {
            ans.push_back(current->val);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            // Find the rightmost node in the left subtree
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                ans.push_back(current->val);
                // Make thread
                predecessor->right = current;
                current = current->left;
            } else {
                // Thread already exists; remove it
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

    // Function to return a list containing the inorder traversal of the tree.
    vector<int> preorderTraversal(TreeNode* root) {
        // Your code here
        vector<int>ans;
        morrispreorder(root,ans);
        return ans;
    }
};