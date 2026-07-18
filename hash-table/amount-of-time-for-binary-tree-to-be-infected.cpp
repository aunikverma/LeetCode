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
    TreeNode*
    createparentmapping(TreeNode* root, int target,unordered_map<TreeNode*, TreeNode*>& nodetoparent) {
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root); // using bfs level order
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->val == target) {
                res = temp;
            }

            if (temp->left) {                    // left
                nodetoparent[temp->left] = temp; // node to parent mapping
                q.push(temp->left);
            }
            if (temp->right) { // right
                nodetoparent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }

    int burntree(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& nodetoparent) {
        int ans = 0;
        map<TreeNode*, bool> visited; // checking for visited

        visited[root] = true; // base case

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            bool v = 0; // false

            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) // left
                {
                    q.push(front->left);
                    visited[front->left] = 1;
                    v = 1;
                }
                if (front->right && !visited[front->right]) // right
                {
                    q.push(front->right);
                    visited[front->right] = 1;
                    v = 1;
                }
                if (nodetoparent[front] &&
                    !visited[nodetoparent[front]]) // parent node
                {
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]] = 1;
                    v = 1;
                }
            }
            if (v) {
                ans++; // if any element is added in queue then increment ans
            }
        }
        return ans;
    }

public:
    int amountOfTime(TreeNode* root, int target) {
        // 1 > create parent mapping
        // 2 > find target node
        // 3 > burn in min time

        unordered_map<TreeNode*, TreeNode*>
            nodetoparent; // mapping node to parent

        TreeNode* targetNode = createparentmapping(
            root, target, nodetoparent); // create mapping and find target node

        int ans = burntree(targetNode, nodetoparent); // minimum burn time

        return ans;
    }
};