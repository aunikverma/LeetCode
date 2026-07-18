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
    TreeNode* minVal(TreeNode* root) { //to find succesor
        TreeNode* temp = root;
        while (temp->left) {
            temp = temp->left;
        }
        return temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            // case - 1
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // case - 2 one child
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (root->right != NULL && root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // case - 3 two child
            if (root->right != NULL && root->left != NULL) {
                int mini = minVal(root->right)->val; //root val to succesor val
                root->val = mini;
                root->right = deleteNode(root->right, mini); //now delete root val
                return root;
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key); //move left
        } else {
            root->right = deleteNode(root->right, key);//move right
        }
        return root;
    }
};