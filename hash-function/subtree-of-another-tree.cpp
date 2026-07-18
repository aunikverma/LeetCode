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
    bool isSame(TreeNode* p, TreeNode* q) { //check same tree code
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right));
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) {
            return (root == subRoot); //if both null
        }
        if (root->val == subRoot->val) { //if root same
            if(isSame(root,subRoot)) return true; //value may equal but tree can be unequal
        }
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)); //else check in left and in right
    }
};